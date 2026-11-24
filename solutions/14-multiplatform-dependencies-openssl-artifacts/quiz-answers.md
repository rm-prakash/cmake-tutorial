# Chapter 14 — Knowledge Check Answer Key

1. **Host** runs the compiler; **target** runs the produced binary.
2. They use distinct OS ABIs, system libraries, and runtime conventions despite sharing x86-64 CPU instructions.
3. It locates an OpenSSL Crypto development dependency according to CMake's search behavior; it does **not** prove origin, ABI approval, secure runtime configuration, or FIPS validation.
4. Imported targets carry include and link usage requirements and avoid guessing library names and search paths.
5. A target representing an existing library built outside the current project; it points CMake to the installed artifact and its interface.
6. Static archives normally package their own object files; external link dependencies remain for the final link, often as link-only transitive requirements.
7. An attacker can replace both artifact and colocated checksum; use trusted signed/pinned metadata or controlled authenticated repository metadata.
8. **Fail the build** without fallback.
9. `CMAKE_TOOLCHAIN_FILE`, `ANDROID_ABI`, and `ANDROID_PLATFORM`, plus CMake's target system variables.
10. Inspect package target metadata, ELF machine information, archive members, NDK toolchain provenance, and binary dependencies.
11. Authentic bytes prove an identified source only when provenance checks are trustworthy; FIPS operation depends on exact validated module, configuration, approved algorithms and operational requirements.
12. The cache binds toolchain, ABI, compiler, and discovered packages; reusing it crosses incompatible target contexts.
13. MSVC Debug and Release commonly differ in runtime library choice, ABI-relevant settings, and dependency build configuration.
14. At resolution/configure time, whenever the mismatch can be determined there.
15. A compatible target device/emulator test run with logs and outcome, not merely successful cross-compilation/linking.

## Suggested assignment grading

- A: Five complete OS/ABI rows; correctly names target variables.
- B: Independently pinned expected version; intentional failure visible.
- C: Header checksum verified; header-only mutation rejected.
- D: Distinct producer/consumer build configurations and MSVC runtime rules; no silent mixing.
- E: Useful imported-property diagnostics, including configuration-specific caveats.
- F: Explicit lockfile, trusted provenance, cache isolation, credentials, offline policy, rollback and rejection tests.
- G: Actual Android-target archive and build logs; correct distinction between build and runtime tests.
