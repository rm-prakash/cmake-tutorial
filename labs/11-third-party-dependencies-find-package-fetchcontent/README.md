# Chapter 11 Laboratory — External Dependencies

Two working integration paths are supplied: `FETCH` uses a local source dependency; `PACKAGE` uses the same library prebuilt and installed into a staging prefix. No network or proprietary package manager is required.

## Linux/macOS shell (Linux verified)

```bash
cd labs/11-third-party-dependencies-find-package-fetchcontent/solution
cmake -S vendor/telemetrycodec -B build/codec -G Ninja -DCMAKE_INSTALL_PREFIX="$PWD/build/prefix"
cmake --build build/codec
cmake --install build/codec
cmake -S . -B build/package -G Ninja -DEMBEDDEDCORE_DEPENDENCY_MODE=PACKAGE -DCMAKE_PREFIX_PATH="$PWD/build/prefix"
cmake --build build/package
ctest --test-dir build/package --output-on-failure
./build/package/DeviceSimulator
cmake -S . -B build/fetch -G Ninja -DEMBEDDEDCORE_DEPENDENCY_MODE=FETCH
cmake --build build/fetch
ctest --test-dir build/fetch --output-on-failure
```

## Windows: VS 2019 x64 Native Tools Command Prompt

```bat
cd labs\11-third-party-dependencies-find-package-fetchcontent\solution
cmake -S vendor/telemetrycodec -B build/codec -G Ninja -DCMAKE_INSTALL_PREFIX=%CD%/build/prefix
cmake --build build/codec
cmake --install build/codec
cmake -S . -B build/package -G Ninja -DEMBEDDEDCORE_DEPENDENCY_MODE=PACKAGE -DCMAKE_PREFIX_PATH=%CD%/build/prefix
cmake --build build/package
ctest --test-dir build/package --output-on-failure
build\package\DeviceSimulator.exe
cmake -S . -B build/fetch -G Ninja -DEMBEDDEDCORE_DEPENDENCY_MODE=FETCH
cmake --build build/fetch
ctest --test-dir build/fetch --output-on-failure
```

## Student investigations

1. Compare the compiler commands and link command in both modes (`cmake --build ... --verbose`).
2. Deliberately change `find_package(TelemetryCodec 1.2 CONFIG REQUIRED)` to request version 2.0. Record the diagnostic.
3. Remove `CMAKE_PREFIX_PATH` from a new build tree and inspect the discovery error.
4. Turn on `CMAKE_FIND_DEBUG_MODE=ON` for one configure and inspect search locations.
5. Change `PRIVATE` linkage to `PUBLIC`: observe which compile-time usage requirements appear on the consumer.
6. Change `SOURCE_DIR` to a nonexistent path and explain the failure.
7. Test a clean offline rebuild using `FETCH` mode; explain why this example is network-free.
8. Inspect `build/prefix/lib/cmake/TelemetryCodec/TelemetryCodecTargets.cmake` and the generated version file.

## Expected output

```text
Embedded Device Simulator
Temperature: 25.5 C
Device status: HEALTHY
Telemetry: TEMP:25.5
```

Generated `build/` directories are ignored by Git. Keep separate build trees for different dependency modes, OS targets and ABIs.
