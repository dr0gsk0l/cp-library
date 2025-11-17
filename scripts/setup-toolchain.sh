#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${ROOT_DIR}"

PCH_DIR="${ROOT_DIR}/build/pch"
mkdir -p "${PCH_DIR}"
PCH_HEADER_SRC="${ROOT_DIR}/scripts/pch/stdc++.hpp"
PCH_HEADER_DST="${PCH_DIR}/stdc++.hpp"
PCH_PATH="${PCH_HEADER_DST}.gch"

enable_ccache_path() {
    local candidates=(
        "/opt/homebrew/opt/ccache/libexec"
        "/usr/local/opt/ccache/libexec"
        "/usr/lib/ccache"
    )
    for dir in "${candidates[@]}"; do
        if [[ -d "${dir}" ]]; then
            export PATH="${dir}:${PATH}"
            echo "[setup-toolchain] ccache wrapper を PATH に追加: ${dir}"
            return 0
        fi
    done
    return 1
}

if command -v ccache >/dev/null 2>&1; then
    enable_ccache_path || echo "[setup-toolchain] ccache wrapper パスを検出できませんでした。"
else
    echo "[setup-toolchain] ccache が見つかりません。Homebrew で 'brew install ccache' を推奨します。"
fi

PREFERRED_GXX=${CXX:-g++-14}
if ! command -v "${PREFERRED_GXX}" >/dev/null 2>&1; then
    if command -v g++-14 >/dev/null 2>&1; then
        PREFERRED_GXX="g++-14"
    elif command -v g++ >/dev/null 2>&1; then
        PREFERRED_GXX="g++"
    else
        echo "[setup-toolchain] g++ が見つかりません。Homebrew で 'brew install gcc' を実行してください。" >&2
        exit 1
    fi
fi
echo "[setup-toolchain] 使用コンパイラ: ${PREFERRED_GXX}"

cp "${PCH_HEADER_SRC}" "${PCH_HEADER_DST}"

hash_cmd() {
    if command -v shasum >/dev/null 2>&1; then
        shasum -a 256 "$@"
    elif command -v sha256sum >/dev/null 2>&1; then
        sha256sum "$@"
    else
        echo "[setup-toolchain] sha256 を計算するコマンド(shasum/sha256sum)が見つかりません。" >&2
        exit 1
    fi
}

HEADER_HASH="$(hash_cmd "${PCH_HEADER_SRC}" | awk '{print $1}')"
CURRENT_HASH="$(printf '%s\n' "${PREFERRED_GXX}" "$( "${PREFERRED_GXX}" -v 2>&1 )" "${HEADER_HASH}" | hash_cmd | awk '{print $1}')"
NEED_PCH=true
if [[ -f "${PCH_PATH}" && -f "${PCH_PATH}.src-hash" ]]; then
    if [[ "$(cat "${PCH_PATH}.src-hash")" == "${CURRENT_HASH}" ]]; then
        NEED_PCH=false
    fi
fi

if [[ "${NEED_PCH}" == true ]]; then
    echo "[setup-toolchain] stdc++.hpp の PCH を再生成します。"
    "${PREFERRED_GXX}" -std=gnu++23 -O0 -x c++-header "${PCH_HEADER_DST}" -o "${PCH_PATH}"
    printf '%s\n' "${CURRENT_HASH}" > "${PCH_PATH}.src-hash"
else
    echo "[setup-toolchain] 既存の PCH を再利用します。"
fi

echo "[setup-toolchain] 完了しました。"
