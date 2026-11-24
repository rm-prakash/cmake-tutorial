# Chapter 13 lab — Cross-compilation, Toolchains, Architectures and ABIs

Complete textbook: [`chapters/13-cross-compilation-toolchains-architectures-abis/README.md`](../../chapters/13-cross-compilation-toolchains-architectures-abis/README.md)

## Layout

- `starter/`: native-build scaffold; complete the exercises and architecture validation.
- `solution/`: full native project, Android NDK scripts, Linux AArch64 example toolchain, CTest.

## Linux

```bash
cd solution
cmake --preset linux-debug
cmake --build --preset linux-debug
ctest --preset linux-debug
./build/linux-debug/DeviceSimulator
```

## Windows (VS2019 x64 Native Tools Command Prompt)

```bat
cd solution
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
ctest --preset windows-msvc-debug
build\windows-msvc-debug\DeviceSimulator.exe
```

## Android NDK

Install a supported NDK, set `ANDROID_NDK_HOME`, then run the provided script:

```bash
cd solution
bash scripts/build-android.sh
```

On Windows PowerShell run `./scripts/build-android.ps1` from the solution directory.
Android device tests require a compatible emulator or device; this chapter builds static libraries only for Android.
