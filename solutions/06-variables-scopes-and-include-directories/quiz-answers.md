# Chapter 06 — Answer key

1. `set(X value)` creates or updates a normal variable in the current scope; `set(X value CACHE STRING "...")` declares a persistent cache entry (unless one already exists).
2. Normal variables shadow cache variables of the same name during ordinary `${X}` lookup.
3. `include()` executes in the caller's variable scope; `function()` introduces a local variable scope; `add_subdirectory()` creates a child directory scope.
4. `PARENT_SCOPE` can send a result to a caller's scope, but does not update the local variable itself.
5. `CMAKE_CURRENT_SOURCE_DIR` points to the directory currently being processed in the source tree; `CMAKE_CURRENT_BINARY_DIR` points to its corresponding build directory.
6. `target_include_directories()` gives the compiler header search directories; `#include` tells the preprocessor which header to find.
7. `configure_file(... @ONLY)` substitutes `@NAME@` placeholders and writes a generated file, usually to the build tree.
8. A quoted `-DDEVICE_LABEL=SensorNode-B` sets a cache value that persists across reconfiguration unless changed or the cache is removed.
9. PRIVATE for a generated header used only inside `.cpp` sources; PUBLIC if consumers' headers need it (and installation must provide it later).
10. Avoid source-tree generated files, shared build trees for different targets, and unnecessary global include directories.
