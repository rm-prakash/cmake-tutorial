# Chapter 12 — Knowledge check answers

1. `target_compile_options` adds compiler flags, not linker flags.
2. `target_compile_definitions` supplies preprocessor macros; omit `-D`/`/D` prefixes.
3. `PRIVATE` affects owner; `PUBLIC` owner and consumers; `INTERFACE` consumers only.
4. `$<CONFIG:Debug>` evaluates in the generation context for a configuration.
5. A normal `if(CMAKE_BUILD_TYPE STREQUAL "Debug")` is not suitable for multi-config selection.
6. `CMAKE_SYSTEM_NAME` describes target system, whereas `CMAKE_HOST_SYSTEM_NAME` describes build host.
7. `target_compile_features(... cxx_std_17)` expresses language standard requirements.
8. `MSVC` reflects an MSVC-like command-line environment; `CMAKE_CXX_COMPILER_ID` identifies compiler vendor.
9. Compile flags are not link flags; use `target_link_options` when required.
10. `CMAKE_EXPORT_COMPILE_COMMANDS` gives a command database with Ninja/Makefile generators.
11. Each Android ABI requires a separate build tree due to different compiler/toolchain cache state.
12. Disabling a warning should be deliberate, narrowly scoped, and justified.
