# Chapter 04 Lab — First Real CMake Project

1. Read [`../../chapters/04-first-real-cmake-project/README.md`](../../chapters/04-first-real-cmake-project/README.md).
2. Work in `starter/` and complete five TODOs in `CMakeLists.txt`.
3. On Linux: `cmake -S starter -B starter/build -G Ninja -DCMAKE_BUILD_TYPE=Debug`, then `cmake --build starter/build` and `./starter/build/DeviceSimulator`.
4. On Windows, open **x64 Native Tools Command Prompt for VS 2019** and configure with `cmake -S starter -B starter/build -G Ninja -DCMAKE_BUILD_TYPE=Debug`, then `cmake --build starter/build` and `starter\build\DeviceSimulator.exe`.
5. Compare with `solution/CMakeLists.txt` only after attempting the TODOs.
6. Try `cmake --build ... --verbose`, examine `CMakeCache.txt`, and use a second build folder for Release.

For a multi-config demonstration, use a **fresh** directory and `-G "Ninja Multi-Config"`, then `cmake --build <dir> --config Release`. Do not change the generator within an existing build tree.
