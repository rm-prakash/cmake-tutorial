# Chapter 07 — Knowledge check answers

1. **B** — `CMAKE_BUILD_TYPE` selects configuration for single-config generators such as Ninja.
2. **C** — Multi-config generators select configurations at build time with `--config`.
3. **A** — `$<CONFIG:Debug>` is a generator expression evaluated for that configuration.
4. **B** — Separate output/build trees prevent cache and generated-file collisions for single-config Debug and Release.
5. **D** — `ctest -C Debug` selects the matching test executable with a multi-config generator.
6. **True** — One Ninja Multi-Config build tree can hold Debug and Release for one configured target ABI/toolchain.
7. **False** — `CMAKE_BUILD_TYPE` does not select the configuration when building with Ninja Multi-Config.
8. **B** — Compiler defaults and platform flags determine the actual command; inspect verbose output.
9. **A, C** — `PUBLIC` definitions propagate to consumers, and a build directory's cache preserves configuration choices.
10. **D** — Use a fresh build directory when changing an Android ABI or toolchain.
