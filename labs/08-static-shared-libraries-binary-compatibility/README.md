# Chapter 8 lab — Static and shared EmbeddedCore

Use `starter/` to practice and `solution/` as a reference.

## Linux

```bash
cd solution
cmake --preset ninja-static
cmake --build --preset static
ctest --preset static
cmake --preset ninja-shared
cmake --build --preset shared
ctest --preset shared
```

## Windows (x64 Native Tools Command Prompt for VS 2019)

```bat
cd solution
cmake -S . -B build\win-shared -G Ninja -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build\win-shared
ctest --test-dir build\win-shared --output-on-failure
```

Compare the resulting artifacts, link commands, runtime dependency behavior, and exports. See the textbook for the full experiment set.
