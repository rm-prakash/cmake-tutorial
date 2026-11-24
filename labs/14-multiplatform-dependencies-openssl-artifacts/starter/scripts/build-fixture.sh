#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TARGET_ID="${1:-linux-x86_64}"
if [[ "$TARGET_ID" != "linux-x86_64" ]]; then
  echo "This script builds the native Linux teaching fixture only; cross-compile fixtures with the appropriate toolchain." >&2
  exit 2
fi
cmake -S "$ROOT/fixture" -B "$ROOT/build/fixture/$TARGET_ID" -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX="$ROOT/artifacts/$TARGET_ID"
cmake --build "$ROOT/build/fixture/$TARGET_ID"
cmake --install "$ROOT/build/fixture/$TARGET_ID"
cmake -DROOT="$ROOT/artifacts/$TARGET_ID" -DTARGET_ID="$TARGET_ID" \
  -DLIB_NAME=libtelemetrycodec.a -P "$ROOT/scripts/write-manifest.cmake"
