# Chapter 11 quiz answers

1. **Config mode** looks for `<Package>Config.cmake` or lowercase equivalent; Module mode looks for `Find<Package>.cmake`.
2. **`CMAKE_PREFIX_PATH`** supplies installation prefixes to be searched; `<Package>_DIR` can point to a directory containing its config file.
3. **Imported target** encapsulates location and usage requirements of an externally built artifact.
4. **`PRIVATE`** propagates requirements needed for a static library's final link as link-only requirements, but not ordinary compile usage requirements to consumers.
5. **`FetchContent`** usually makes sources available during configure; it is not inherently a binary package manager.
6. **A version file** evaluates whether an installed package satisfies a requested version/compatibility range.
7. **Cross compilation** must not resolve incompatible host binaries for target-side linking.
8. **A clean build tree** avoids stale cache paths after changing ABI/toolchain.
9. **Local `SOURCE_DIR`** allows fully offline testing when sources already exist.
10. **Security** requires trusted sources, pinned versions/checksums, proper licensing and vulnerability response.
11. **`find_dependency()`** in a package config is used to discover transitive package requirements.
12. **Headers alone** cannot prove a prebuilt library is for the correct OS/architecture/configuration.
