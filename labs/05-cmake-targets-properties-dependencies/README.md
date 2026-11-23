# Chapter 05 Lab — Target properties and transitive requirements

Start in `starter/` and complete its nine TODOs; compare with `solution/` only after attempting the exercises.

## Linux (Ninja)

```bash
cd labs/05-cmake-targets-properties-dependencies/solution
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build --verbose
ctest --test-dir build --output-on-failure
./build/DeviceSimulator
```

## Windows (Visual Studio 2019 x64 Native Tools Command Prompt)

```bat
cd labs\05-cmake-targets-properties-dependencies\solution
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build --verbose
ctest --test-dir build --output-on-failure
build\DeviceSimulator.exe
```

If Ninja is unavailable, configure with `-G "Visual Studio 16 2019" -A x64` and run `cmake --build build --config Debug` and `ctest --test-dir build -C Debug --output-on-failure`.

## Expected outcome

The contract test passes; the console output reports `HEALTHY` for the 25.5 C sample. The source code's warning threshold is 35 C because `EMBEDDEDCORE_STRICT_LIMIT` is private to the compiled library.

## Experiments

1. Change `target_include_directories(embeddedcore PUBLIC ...)` to `PRIVATE` and observe why the consumer fails to find the library's public headers.
2. Restore `PUBLIC`, then change the config target link from `PUBLIC` to `PRIVATE`. Inspect the consumer's compile command for its C++ language standard; the library can still build, but the consumer no longer inherits that usage requirement.
3. Temporarily change `EMBEDDEDCORE_STRICT_LIMIT` from `PRIVATE` to `PUBLIC`. Inspect the consumer compiler command for the macro, then restore `PRIVATE`.
4. Remove the `target_link_libraries(DeviceSimulator ...)` line. Observe whether the failure is during compilation or linking.
5. Try linking a deliberately misspelled namespace target such as `EmbeddedCore::Croe` to see CMake fail during configuration/generation instead of silently asking the linker for a library.

Restore the solution before running the final CTest gate.
