# Chapter 12 lab — Compiler options, definitions, and generator expressions

The solution builds on Windows (MSVC), Linux (GCC/Clang), and may be cross-compiled with an Android NDK toolchain when configured for a supported ABI. Android execution is not required for this native lab.

## Linux quick start

```bash
cd labs/12-compiler-options-definitions-generator-expressions/solution
cmake --preset ninja-debug
cmake --build --preset debug --verbose
ctest --preset debug
./build/debug/DeviceSimulator
```

## Windows x64 Native Tools Command Prompt (VS 2019)

```bat
cd labs\12-compiler-options-definitions-generator-expressions\solution
cmake -S . -B build\vs2019 -G "Visual Studio 16 2019" -A x64
cmake --build build\vs2019 --config Debug
ctest --test-dir build\vs2019 -C Debug --output-on-failure
build\vs2019\Debug\DeviceSimulator.exe
```

For Ninja with MSVC, run from the initialized **x64 Native Tools Command Prompt**.

## Android configure example

```bash
cmake -S . -B build/android-arm64 -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-24 \
  -DCMAKE_BUILD_TYPE=Release \
  -DEMBEDDEDCORE_BUILD_TESTS=OFF
cmake --build build/android-arm64
```

Use separate build trees for Android `armeabi-v7a`, `arm64-v8a`, `x86_64`, Linux x86-64, and Windows x64. Compiling an Android executable does **not** mean it can run on the host.
