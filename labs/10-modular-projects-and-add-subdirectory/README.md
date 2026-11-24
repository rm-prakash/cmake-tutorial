# Chapter 10 Lab — Modular EmbeddedCore

The `solution/` project contains four independently defined static library targets, an INTERFACE umbrella target, the DeviceSimulator executable, and two CTest checks.

## Run

```bash
cd solution
cmake --preset ninja-debug
cmake --build --preset debug
ctest --preset debug
```

For Windows, run the same commands in an initialized MSVC x64 developer shell with CMake and Ninja installed. See the chapter textbook for Visual Studio generator alternatives and targeted failure experiments.

## Student assignment

Begin in `starter/` and complete the two TODOs in `app/main.cpp`. Then examine the project target graph and try the dependency exercises in the chapter.
