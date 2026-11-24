# Chapter 8 — Quiz answers

1. An archiver collects object files into an archive; the linker resolves symbols and builds an executable or linked shared binary.
2. It supplies link-time symbols/stubs for DLL exports; the DLL implementation must still be found by the loader.
3. `.lib` can mean a static library archive or a DLL import library.
4. No. Other runtime components, including the C runtime and OS libraries, can remain dynamically linked.
5. When its type is omitted, `BUILD_SHARED_LIBS` controls STATIC versus SHARED at configure time.
6. They use different target kinds and outputs; separate caches avoid invalid or confusing carryover.
7. `dllexport` marks functions/data exported by the DLL; `dllimport` marks imports expected by consuming code.
8. ELF shared objects commonly require position-independent relocation behavior for included static objects.
9. The final executable link may still need libraries that satisfy references retained in the static archive; CMake propagates link-only requirements.
10. SONAME identifies a shared ELF library's interface version; `DT_NEEDED` records runtime dependencies.
11. No. A matching processor alone does not establish the same OS ABI, runtime, linker or platform compatibility.
12. ABI depends on layout, name mangling, calling convention, toolchain, CRT and other binary contracts beyond header spelling.
