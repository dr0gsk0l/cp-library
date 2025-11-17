#!/usr/bin/env bash
set -euo pipefail

# project root から実行し、相対パスを安定化
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${ROOT_DIR}"

# ログのプレフィックスを揃える
ce_log() {
    echo "[ce-check] $*"
}
log_err() {
    echo "[ce-check] $*" >&2
}

# 直近のログを毎回作り直す（CI artifact 用）
LOG_DIR="${ROOT_DIR}/build/ce-check"
rm -rf "${LOG_DIR}"
mkdir -p "${LOG_DIR}"
touch "${LOG_DIR}/.keep"

SETUP_SCRIPT="${ROOT_DIR}/scripts/setup-toolchain.sh"
if [[ -x "${SETUP_SCRIPT}" ]]; then
    "${SETUP_SCRIPT}" >/dev/null
fi

# ccache のラッパーがあれば PATH に追加
enable_ccache_path() {
    local candidates=(
        "/opt/homebrew/opt/ccache/libexec"
        "/usr/local/opt/ccache/libexec"
        "/usr/lib/ccache"
    )
    for dir in "${candidates[@]}"; do
        if [[ -d "${dir}" ]]; then
            export PATH="${dir}:${PATH}"
            return
        fi
    done
}

if command -v ccache >/dev/null 2>&1; then
    enable_ccache_path || true
fi

PCH_HEADER="${ROOT_DIR}/build/pch/stdc++.hpp"
if [[ ! -f "${PCH_HEADER}.gch" ]]; then
    log_err "PCH (${PCH_HEADER}.gch) が見つかりません。scripts/setup-toolchain.sh を実行してください。"
    exit 1
fi

CXX_BIN="${CXX:-g++-14}"
if ! command -v "${CXX_BIN}" >/dev/null 2>&1; then
    if command -v g++-14 >/dev/null 2>&1; then
        CXX_BIN="g++-14"
    elif command -v g++ >/dev/null 2>&1; then
        CXX_BIN="g++"
    else
        log_err "利用可能な C++ コンパイラが見つかりません。CXX を設定してください。"
        exit 1
    fi
fi

CXX_FLAGS=(
    -std=gnu++23
    -O0
    -w
    -I
    ac-library
    -I
    .
    -fsyntax-only
    -Winvalid-pch
    -include
    "${PCH_HEADER}"
)

# GitHub Actions の注釈で使えるようにログ文字列をエスケープ
escape_github_message() {
    local text="$1"
    text="${text//'%'/'%25'}"
    text="${text//$'\n'/'%0A'}"
    text="${text//$'\r'/'%0D'}"
    printf '%s' "${text}"
}

TEST_SOURCES=()
if command -v rg >/dev/null 2>&1; then
    while IFS= read -r path; do
        [[ -n "${path}" ]] && TEST_SOURCES+=("${path}")
    done < <(rg --files -g '*.test.cpp' test | sort)
else
    while IFS= read -r path; do
        [[ -n "${path}" ]] && TEST_SOURCES+=("${path}")
    done < <(find test -name '*.test.cpp' | sort)
fi

if [[ ${#TEST_SOURCES[@]} -eq 0 ]]; then
    ce_log "test ディレクトリに *.test.cpp が見つかりません。"
    exit 0
fi

# 1 ファイルの構文チェックを実行し、失敗時はログと GHA 注釈を出す
compile_one() {
    local src="$1"
    local safe_name="${src//\//_}"
    safe_name="${safe_name// /_}"
    local log_file="${LOG_DIR}/${safe_name}.log"
    ce_log "${src}"
    if "${CXX_BIN}" "${CXX_FLAGS[@]}" "${src}" >"${log_file}" 2>&1; then
        rm -f "${log_file}"
        return 0
    fi

    ce_log "[ERROR] ${src}"
    local snippet
    snippet="$(tail -n 20 "${log_file}")"
    printf '%s\n' "${snippet}"
    if [[ -n "${GITHUB_ACTIONS:-}" ]]; then
        printf '::error file=%s::%s\n' "${src}" "$(escape_github_message "${snippet}")"
    fi
    return 1
}

ce_log "${#TEST_SOURCES[@]} 件のテストを構文チェックします。"
JOB_COUNT="${CE_CHECK_JOBS:-}"
if [[ -z "${JOB_COUNT}" ]]; then
    if command -v sysctl >/dev/null 2>&1; then
        JOB_COUNT="$(sysctl -n hw.logicalcpu 2>/dev/null || echo 1)"
    else
        JOB_COUNT="$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)"
    fi
fi
if [[ "${JOB_COUNT}" -lt 1 ]]; then
    JOB_COUNT=1
fi
ce_log "並列ジョブ数: ${JOB_COUNT}"

if [[ "${JOB_COUNT}" -eq 1 ]]; then
    for src in "${TEST_SOURCES[@]}"; do
        if ! compile_one "${src}"; then
            ce_log "失敗: ${src}"
            exit 1
        fi
    done
    exit 0
fi

declare -a pids=()
running=0
for src in "${TEST_SOURCES[@]}"; do
    compile_one "${src}" &
    pids+=("$!")
    ((running++))
    if ((running >= JOB_COUNT)); then
        if ! wait "${pids[0]}"; then
            exit 1
        fi
        pids=("${pids[@]:1}")
        ((running--))
    fi
done

for pid in "${pids[@]}"; do
    if ! wait "${pid}"; then
        exit 1
    fi
done

ce_log "すべてのテストがコンパイルに成功しました。"
