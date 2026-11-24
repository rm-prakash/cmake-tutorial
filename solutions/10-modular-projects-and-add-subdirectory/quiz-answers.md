# Chapter 10 — Quiz key

1. B — `add_subdirectory()` processes a child `CMakeLists.txt` during configure.
2. C — CMake targets can be referenced across directory scopes, subject to target visibility and naming rules.
3. A — `target_include_directories(... PUBLIC ...)` serves both the target and its consumers.
4. D — `INTERFACE` targets carry requirements without producing a linked library binary.
5. B — A target link dependency creates ordering and usage requirement relationships.
6. A — A target's PRIVATE compile requirements do not normally propagate.
7. C — `CMAKE_CURRENT_SOURCE_DIR` refers to the directory currently being processed.
8. B — Independent library targets make component boundaries observable.
9. D — Avoid global include paths when target-level paths suffice.
10. C — Cross-ABI builds require separate toolchain-specific build trees.
11. A — A static library PRIVATE link dependency may still be needed by the final linker.
12. B — CMake configure, generate, and build are distinct activities.
