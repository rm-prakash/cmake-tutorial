# Chapter 03 lab — Automating the EmbeddedCore build

Chapter lesson: [Make, Ninja and CMake](../../chapters/03-make-ninja-and-cmake/README.md)

- `starter/`: C++ sources from Chapter 02 plus TODO build files.
- `solution/`: tested GNU Make, Ninja, and CMake builds for the same application.
- `build/` is ignored by Git.

## Linux / WSL / MSYS2 (with GNU Make, Ninja, GCC)

```bash
cd labs/03-make-ninja-and-cmake/solution
make -j2
./build/make/DeviceSimulator
make -n
ninja -f build.ninja
./build/ninja/DeviceSimulator
ninja -f build.ninja -n
cmake -S . -B build/cmake -G Ninja
cmake --build build/cmake
./build/cmake/DeviceSimulator
```

## Windows (VS 2019 x64 Native Tools prompt)

```bat
cd labs\03-make-ninja-and-cmake\solution
cmake -S . -B build\windows -G Ninja
cmake --build build\windows
build\windows\DeviceSimulator.exe
```

The Makefile and manually authored `build.ninja` are GCC/GNU-style educational examples; for native MSVC on Windows, use the CMake example, which generates the appropriate Ninja rules.

## Experiments

1. Run the Make and Ninja builds a second time. No source should need recompilation.
2. Modify `src/sensor.cpp`, rebuild, and observe which targets are updated.
3. Touch `include/embeddedcore/sensor.hpp`, rebuild, and observe header dependency tracking.
4. Run `make clean`, `ninja -f build.ninja -t clean`, and `cmake --build build/cmake --target clean` separately and compare results.

For solutions and explanation, see the chapter and the separate quiz answer file.
