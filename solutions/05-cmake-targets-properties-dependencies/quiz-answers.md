# Chapter 05 — Quiz answers and explanations

1. **B — A CMake target.** A target carries build properties and usage requirements.
2. **C — PUBLIC.** The library uses the include directory itself and publishes it to its consumers.
3. **A — PRIVATE.** Internal implementation macros should not normally appear on consumer compile commands.
4. **D — INTERFACE.** An interface library can carry requirements without compiling an archive.
5. **B — target_link_libraries().** Target-based linking propagates compatible usage requirements transitively.
6. **False.** A target's PRIVATE include directories do not automatically propagate to consumers.
7. **True.** The alias `EmbeddedCore::Core` refers to the existing local target; it does not generate a second compiled library.
8. **B — get_target_property().** It inspects a CMake target's property during configuration.
9. **A — During final linking.** Removing the static library can leave referenced functions undefined even though main.cpp compiles.
10. **C — Build interface.** BUILD_INTERFACE represents paths used while building from the source tree.
