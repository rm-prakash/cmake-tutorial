# Chapter 07 lab: Debug and Release

The starter and solution are complete, self-contained C++17 projects.

## Linux GCC/Clang with Ninja

```bash
cd solution
cmake --preset ninja-debug
cmake --build --preset debug
ctest --preset debug
./build/ninja-debug/DeviceSimulator
cmake --preset ninja-release
cmake --build --preset release
ctest --preset release
./build/ninja-release/DeviceSimulator
```

## Ninja Multi-Config (Linux or Windows)

```bash
cmake --preset ninja-multi
cmake --build --preset multi-debug
cmake --build --preset multi-release
ctest --preset multi-debug
ctest --preset multi-release
```

On Windows run these in an **x64 Native Tools Command Prompt for VS 2019**, with recent CMake and Ninja available. The executables are usually under `build/ninja-multi/Debug/DeviceSimulator.exe` and `build/ninja-multi/Release/DeviceSimulator.exe`.

## Inspect commands

Ninja single-config: `cmake --build build/ninja-debug --verbose --clean-first`.

Ninja Multi-Config: `cmake --build build/ninja-multi --config Debug --verbose --clean-first`.

Do not interpret identical output from Debug and Release as identical binaries: inspect compiler flags and build configuration definitions.
