#!/usr/bin/env bash
set -euo pipefail
[[ $# == 2 ]] || { echo "Usage: ci-build.sh <target> <Debug|Release>" >&2; exit 2; }
TARGET="$1"; CONFIG="$2"
case "$CONFIG" in Debug|Release) ;; *) echo 'Invalid build configuration' >&2; exit 2;; esac
ARGS=()
case "$TARGET" in
  linux-x86_64)
    [[ "$(uname -s)" == Linux && "$(uname -m)" == x86_64 ]] || { echo 'Linux x86-64 host required' >&2; exit 2; };;
  android-armeabi-v7a|android-arm64-v8a|android-x86_64)
    : "${ANDROID_NDK_HOME:?Android NDK must be explicitly configured}"
    [[ -f "$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" ]] || { echo 'Missing NDK toolchain' >&2; exit 2; }
    ARGS=(-DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" -DANDROID_ABI="${TARGET#android-}" -DANDROID_PLATFORM=android-24 -DBUILD_TESTING=OFF);;
  *) echo 'Unsupported target' >&2; exit 2;;
esac
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD="$ROOT/build/$TARGET/$CONFIG"
STAGE="$ROOT/out/stage/$TARGET/$CONFIG"
CONSUMER="$ROOT/build-consumer/$TARGET/$CONFIG"
mkdir -p "$ROOT/out/artifacts"
cmake -S "$ROOT" -B "$BUILD" -G Ninja -DCMAKE_BUILD_TYPE="$CONFIG" "${ARGS[@]}"
cmake --build "$BUILD" --parallel
if [[ "$TARGET" == linux-* ]]; then
  ctest --test-dir "$BUILD" --output-on-failure --output-junit "$BUILD/producer-junit.xml"
fi
cmake --install "$BUILD" --prefix "$STAGE"
cmake -S "$ROOT/consumer" -B "$CONSUMER" -G Ninja -DCMAKE_BUILD_TYPE="$CONFIG" -DCMAKE_PREFIX_PATH="$STAGE" "${ARGS[@]}"
cmake --build "$CONSUMER" --parallel
if [[ "$TARGET" == linux-* ]]; then
  ctest --test-dir "$CONSUMER" --output-on-failure --output-junit "$CONSUMER/consumer-junit.xml"
fi
python3 "$ROOT/scripts/package.py" "$STAGE" "$ROOT/out/artifacts" "$TARGET" "$CONFIG"
