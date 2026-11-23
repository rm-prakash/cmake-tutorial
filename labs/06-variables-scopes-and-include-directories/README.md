# Chapter 06 lab — variables, scopes, and include directories

This lab extends the Chapter 05 EmbeddedCore project. It uses a generated private header for device configuration and demonstrates variable scopes.

## Requirements
- CMake 3.20+; C++17 compiler; Ninja (or another supported generator)
- Windows: x64 Native Tools Command Prompt for VS 2019 (with Ninja installed)
- Linux: GCC or Clang and Ninja

## Solution: configure, build, test

From `solution/` on Linux:

```bash
cmake -S . -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DDEVICE_LABEL=SensorNode-B -DEMBEDDEDCORE_STRICT_LIMIT=ON
cmake --build build/debug --verbose
ctest --test-dir build/debug --output-on-failure
./build/debug/DeviceSimulator
```

From `solution\` in Windows x64 Native Tools Command Prompt:

```bat
cmake -S . -B build\debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DDEVICE_LABEL=SensorNode-B -DEMBEDDEDCORE_STRICT_LIMIT=ON
cmake --build build\debug --verbose
ctest --test-dir build\debug --output-on-failure
build\debug\DeviceSimulator.exe
```

Reconfigure the same build tree with `-DEMBEDDEDCORE_STRICT_LIMIT=OFF` to see threshold change; it generates a different private header and causes recompilation of dependent sources.

## Starter assignment

The starter is intentionally incomplete and will fail until you complete four TODOs in its `CMakeLists.txt`. Compare only after attempting the exercise.

## Inspect the cache

```bash
cmake -LAH -N build/debug
```

On Windows, use `build\debug` instead. `-LAH` lists visible cached variables and help; `-N` loads cache without reconfiguring.

## Expected run output

```text
Embedded Device Simulator
Device: SensorNode-B
Temperature: 25.5 C
Device status: HEALTHY
```
