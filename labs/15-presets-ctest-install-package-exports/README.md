# Chapter 15 laboratory — reproducible packaging

## Prerequisites
CMake >= 3.23, Ninja, C++17 compiler. Windows: VS 2019 Developer Command Prompt with Ninja.

## A. Native package, Ninja Debug
```sh
cmake -S solution -B solution/build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build solution/build/debug
ctest --test-dir solution/build/debug --output-on-failure
cmake --install solution/build/debug --prefix solution/stage/debug
cmake -S independent-consumer -B independent-consumer/build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH="$(pwd)/solution/stage/debug"
cmake --build independent-consumer/build/debug
ctest --test-dir independent-consumer/build/debug --output-on-failure
```
Use a platform-appropriate absolute prefix on Windows, for example `%CD%\solution\stage\debug`.

## B. Relocation
Copy `solution/stage/debug` to a different location, rename or remove the original install prefix, and point a **fresh consumer build tree** at the copied prefix. Do not reuse the original consumer cache.

## C. Optional external dependency, install order matters
1. Configure/build/install `telemetrycodec/` into a staging prefix.
2. Configure/build/install EmbeddedCore with `-DEMBEDDEDCORE_WITH_TELEMETRY=ON -DCMAKE_PREFIX_PATH=<prefix>` to the same prefix.
3. Configure the independent consumer with that prefix. Check `find_dependency()` resolution.
4. Copy the entire prefix and rebuild a fresh consumer against the copy.

## D. Negative tests
- Request `find_package(EmbeddedCore 2.0 CONFIG REQUIRED)` and observe version rejection.
- Remove `TelemetryCodecConfig.cmake` from a duplicate dependency-enabled install and observe the consumer configuration fail.
- Remove exported headers from a copied installation and inspect the compiler failure.
- Disable `BUILD_TESTING` and observe that no test executable is built.

## Questions
Why is the `EmbeddedCoreTargets.cmake` **generated**? Why should a consumer never import a target pointing into the producer's original source tree? Explain `CMAKE_PREFIX_PATH` versus `EmbeddedCore_DIR`.
