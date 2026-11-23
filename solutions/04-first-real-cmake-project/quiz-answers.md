# Chapter 04 — Quiz answers

1. **B** — `cmake -S . -B build` configures and generates build files; `cmake --build build` executes the build.
2. **C** — `CMakeLists.txt` is CMake's main source-project description.
3. **A** — `project()` gives the project its name and enables selected languages.
4. **B** — A build directory holds CMake-generated files, cache, and binary outputs.
5. **D** — `add_library(... STATIC ...)` creates a static library target.
6. **A** — `target_link_libraries()` expresses target dependencies.
7. **C** — `-G Ninja` selects the Ninja generator on first configure.
8. **B** — `CMAKE_BUILD_TYPE` applies to single-config generators such as Ninja.
9. **D** — A cache entry usually persists between reconfigurations in the same build directory.
10. **A** — A changed generator requires a new/clean build directory.
