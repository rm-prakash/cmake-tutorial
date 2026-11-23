# Chapter 2 Lab — EmbeddedCore manual compilation

Read the [full chapter](../../chapters/02-compilers-linkers-and-libraries/README.md) before starting.

The `solution/` folder is a complete, buildable example. The `starter/` folder provides a challenge prompt so you can write the program yourself.

## Linux: build without CMake

Run from `solution/`:

```bash
mkdir -p build
g++ -std=c++17 -Iinclude -c src/sensor.cpp -o build/sensor.o
g++ -std=c++17 -Iinclude -c src/diagnostics.cpp -o build/diagnostics.o
ar rcs build/libembeddedcore.a build/sensor.o build/diagnostics.o
g++ -std=c++17 -Iinclude app/main.cpp build/libembeddedcore.a -o build/DeviceSimulator
./build/DeviceSimulator
```

## Windows: VS 2019 x64 Native Tools Command Prompt

Run from `solution/`:

```bat
mkdir build
cl /nologo /EHsc /std:c++17 /Iinclude /c src\sensor.cpp /Fo:build\sensor.obj
cl /nologo /EHsc /std:c++17 /Iinclude /c src\diagnostics.cpp /Fo:build\diagnostics.obj
lib /nologo /OUT:build\embeddedcore.lib build\sensor.obj build\diagnostics.obj
cl /nologo /EHsc /std:c++17 /Iinclude app\main.cpp build\embeddedcore.lib /Fe:build\DeviceSimulator.exe
build\DeviceSimulator.exe
```
