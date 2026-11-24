# Chapter 09 — Quiz answers

1. **Build time vs runtime:** Linking validates and records dependencies; the loader resolves required shared binaries when the program starts.
2. **Windows placement:** Place required DLLs alongside the executable in a staged application layout (or use a documented application directory strategy).
3. **Linux ELF inspection:** `readelf -d` shows `NEEDED`, `RPATH`, and/or `RUNPATH` entries.
4. **`$ORIGIN`:** The directory of the ELF object whose dynamic tags are being evaluated.
5. **`$<TARGET_RUNTIME_DLLS:...>`:** A generator expression for known runtime DLLs of a target; primarily useful for Windows runtime copying.
6. **Private shared dependency:** The executable may not directly link the transport library, but its dependent shared library needs it at runtime.
7. **`install(TARGETS)`:** Specifies how target artifacts are staged into an install prefix.
8. **`--config`:** Required to select the intended configuration for multi-config generators.
9. **Cross-build caution:** Do not run an Android-targeted ELF executable on a Linux x86-64 host.
10. **ABI:** Processor architecture, operating system, compiler/runtime compatibility and ABI conventions must match.
11. **Why not rely on PATH/LD_LIBRARY_PATH:** They are external environment assumptions and may leak across programs.
12. **Runtime closure:** Gather all applicable dependent shared binaries, including transitive and third-party dependencies.
