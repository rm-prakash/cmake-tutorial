# Chapter 15 — quiz answers

1. A raw archive lacks public headers, target usage metadata, version/discovery information and dependency requirements.
2. An alias names an in-tree target; a generated imported target represents a library installed elsewhere.
3. `install(TARGETS embeddedcore EXPORT EmbeddedCoreTargets ...)`.
4. `install(EXPORT EmbeddedCoreTargets FILE EmbeddedCoreTargets.cmake ...)`.
5. No; change target properties and regenerate the export.
6. Initializes package-location helper logic used by CMake's package configuration support.
7. It supplies relocation-oriented features and avoids common hardcoded-prefix mistakes.
8. `CMAKE_PREFIX_PATH` lists search prefixes; `EmbeddedCore_DIR` points at the directory with its Config file.
9. Imported targets carry per-config locations, include dirs, compile requirements and link dependencies.
10. They separate source-tree paths from relative install-prefix paths.
11. A static archive contains unresolved references that the final linker must satisfy.
12. `ctest --test-dir build/multi -C Release` or an equivalent CTest test preset with `configuration`.
13. It checks version-family compatibility according to CMake rules; it does not prove ABI compatibility.
14. Hide or remove the original prefix and configure a brand-new consumer build directory pointing at the relocated prefix.
15. Different toolchains, OS ABIs, libraries, machine code and execution environments require separate validation.
