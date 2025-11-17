#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${ROOT_DIR}"

SETUP_SCRIPT="${ROOT_DIR}/scripts/setup-toolchain.sh"
if [[ -x "${SETUP_SCRIPT}" ]]; then
    "${SETUP_SCRIPT}" >/dev/null
fi

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
    echo "[ce-check] PCH (${PCH_HEADER}.gch) が見つかりません。scripts/setup-toolchain.sh を実行してください。" >&2
    exit 1
fi

CXX_BIN="${CXX:-g++-14}"
if ! command -v "${CXX_BIN}" >/dev/null 2>&1; then
    if command -v g++-14 >/dev/null 2>&1; then
        CXX_BIN="g++-14"
    elif command -v g++ >/dev/null 2>&1; then
        CXX_BIN="g++"
    else
        echo "[ce-check] 利用可能な C++ コンパイラが見つかりません。CXX を設定してください。" >&2
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
    echo "[ce-check] test ディレクトリに *.test.cpp が見つかりません。"
    exit 0
fi

echo "[ce-check] ${#TEST_SOURCES[@]} 件のテストを構文チェックします。"
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
echo "[ce-check] 並列ジョブ数: ${JOB_COUNT}"

compile_one() {
    local src="$1"
    echo "[ce-check] ${src}"
    "${CXX_BIN}" "${CXX_FLAGS[@]}" "${src}"
}

pids=()
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

echo "[ce-check] すべてのテストがコンパイルに成功しました。"
