# Chapter 09 laboratory — Runtime dependencies and deployment

Work inside `starter/`. Compare your finished CMakeLists.txt with `solution/`.

## Linux (GCC/Clang + Ninja)

```bash
cd labs/09-runtime-dependencies-and-deployment/solution
cmake -S . -B build/linux-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build/linux-debug
ctest --test-dir build/linux-debug --output-on-failure
cmake --install build/linux-debug --prefix "$PWD/stage/linux"
./stage/linux/bin/DeviceSimulator
readelf -d stage/linux/bin/DeviceSimulator | grep -E 'RUNPATH|RPATH|NEEDED'
readelf -d stage/linux/lib/libembeddedcore.so | grep -E 'RUNPATH|RPATH|NEEDED'
```

`lib/` may be `lib64/` on some distributions (controlled by GNUInstallDirs).

## Windows (VS 2019 x64 Native Tools + Ninja)

```bat
cmake -S . -B build\windows -G "Ninja Multi-Config"
cmake --build build\windows --config Debug
ctest --test-dir build\windows -C Debug --output-on-failure
cmake --install build\windows --config Debug --prefix stage\windows
stage\windows\bin\DeviceSimulator.exe
```

Check staged `bin/` for `DeviceSimulator.exe`, `embeddedcore.dll`, and `device_transport.dll`.
Inspect the dependency tree with `dumpbin /DEPENDENTS stage\windows\bin\DeviceSimulator.exe` and `dumpbin /DEPENDENTS stage\windows\bin\embeddedcore.dll`.

## Experimental faults

1. Temporarily move `stage/windows/bin/device_transport.dll` out of `bin`, then run the program; restore it afterwards. The loader should report a missing dependency.
2. On Linux, inspect `RUNPATH` with `readelf`. Temporarily rename the installed transport library, run the executable, and restore it.
3. Remove `INSTALL_RPATH` properties in a throwaway copy and compare how installed binaries behave in an empty environment.
4. Try a different install prefix without rebuilding. Check relative lookup.
5. Try `cmake --build ... --verbose` to distinguish linking errors from loader errors.

Never delete or rename system-installed libraries; use only the isolated `stage/` folder.
