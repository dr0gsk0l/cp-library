#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${ROOT_DIR}"

ce_log() {
    echo "[oj-verify] $*"
}
log_err() {
    echo "[oj-verify] $*" >&2
}

"${ROOT_DIR}/scripts/setup-toolchain.sh"

TOOLCHAIN_BIN="${ROOT_DIR}/build/toolchain/bin"
if [[ -d "${TOOLCHAIN_BIN}" ]]; then
    export PATH="${TOOLCHAIN_BIN}:${PATH}"
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
            ce_log "ccache wrapper enabled: ${dir}"
            return 0
        fi
    done
    return 1
}

if command -v ccache >/dev/null 2>&1; then
    enable_ccache_path || ce_log "ccache wrapper path not found; continuing without it"
else
    ce_log "ccache not installed; continuing without it"
fi

calc_jobs() {
    if command -v python3 >/dev/null 2>&1; then
        python3 - <<'PY'
import multiprocessing
print(max(1, min(8, multiprocessing.cpu_count())))
PY
        return
    fi
    if command -v sysctl >/dev/null 2>&1; then
        sysctl -n hw.logicalcpu 2>/dev/null && return
    fi
    if command -v nproc >/dev/null 2>&1; then
        nproc && return
    fi
    echo 1
}

append_jobs=true
skip_next=false
for arg in "$@"; do
    if [[ "${skip_next}" == true ]]; then
        skip_next=false
        continue
    fi
    case "${arg}" in
        --jobs)
            append_jobs=false
            skip_next=true
            ;;
        --jobs=*)
            append_jobs=false
            ;;
        -j)
            append_jobs=false
            skip_next=true
            ;;
        -j*)
            append_jobs=false
            ;;
    esac
done

ARGS=("$@")
if [[ "${append_jobs}" == true ]]; then
    JOBS="${OJ_VERIFY_JOBS:-$(calc_jobs)}"
    ARGS+=("--jobs" "${JOBS}")
    ce_log "appended --jobs ${JOBS}"
fi

exec oj-verify "${ARGS[@]}"
