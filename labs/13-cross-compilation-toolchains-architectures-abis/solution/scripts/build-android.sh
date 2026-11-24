#!/usr/bin/env bash
set -euo pipefail

if [[ -z "${ANDROID_NDK_HOME:-}" ]]; then
    echo "Set ANDROID_NDK_HOME to an installed NDK directory" >&2
    exit 2
fi
if [[ ! -f "$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" ]]; then
    echo "NDK toolchain file not found" >&2
    exit 2
fi
source_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
api="${ANDROID_API_LEVEL:-24}"
for abi in armeabi-v7a arm64-v8a x86_64; do
    build_dir="$source_dir/build/android/$abi"
    cmake -S "$source_dir" -B "$build_dir" -G Ninja \
        -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" \
        -DANDROID_ABI="$abi" \
        -DANDROID_PLATFORM="android-$api" \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_TESTING=OFF
    cmake --build "$build_dir" --parallel
    cmake --install "$build_dir" --prefix "$source_dir/stage/android/$abi"
done
