# Chapter 13 — Suggested knowledge-check answers

1. **ISA** specifies machine instructions; **ABI** describes binary interoperability, conventions, layout and runtime constraints.
2. Android and Linux differ in system libraries, Bionic vs common glibc environment, packaging and OS ABI even if both use x86-64 instructions.
3. A **sysroot** supplies a target filesystem view (headers and libraries) for cross-compilation.
4. Compiler and target identification happen early; changing them later in the same build cache is unsafe.
5. Windows: it describes the machine running CMake, not the Android target.
6. It reflects CMake cross-compilation setup semantics and is not a proof of whether target programs execute on the host.
7. Set `ANDROID_ABI=arm64-v8a` with the NDK's CMake toolchain.
8. It requests Android API level 24 as the minimum platform level for the build; actual device compatibility must also respect ABI and dependencies.
9. They target different instruction sets, pointer widths, binary ABIs and toolchain settings; each needs isolated cache and objects.
10. No; CTest doesn't supply an Android runtime. Use a compatible emulator/device or a correctly configured execution mechanism.
11. `.a` is an archive of objects; names/extensions do not certify member architecture or target OS.
12. Multi-Config selects build configurations inside one fixed target toolchain/ABI tree; ABI changes require distinct configured trees.
