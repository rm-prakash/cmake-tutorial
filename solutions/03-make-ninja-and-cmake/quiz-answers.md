# Chapter 03 — Answer key

1. **B.** CMake describes/configures builds, while Ninja and Make execute generated or authored dependency rules.
2. **A.** A build graph represents prerequisites and outputs.
3. **C.** With correct dependency tracking, an unchanged input does not cause recompilation.
4. **B.** `make -j4` asks Make to execute up to four eligible jobs concurrently.
5. **A.** `cmake -S . -B build -G Ninja` configures and generates a Ninja build tree.
6. **False.** CMake is not itself a C++ compiler.
7. **True.** Ninja needs a build description such as `build.ninja` before it can schedule compilation.
8. **B.** `target_link_libraries(DeviceSimulator PRIVATE embeddedcore)` expresses the consumer dependency.
9. **C.** Without header dependencies, a changed header may leave stale object files.
10. **A.** Separate out-of-source directories prevent build outputs from cluttering the source tree.
