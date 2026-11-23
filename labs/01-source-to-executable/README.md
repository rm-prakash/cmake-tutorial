# Chapter 01 lab — DeviceSimulator

[← Chapter 01](../../chapters/01-source-to-executable/README.md)

The `starter/` folder contains the exact source used in the lesson. `solution/` demonstrates the optional exercises. You do not need CMake for this lab.

## Windows (VS 2019 x64 Native Tools Command Prompt)

```bat
cd labs\01-source-to-executable\starter
cl /EHsc main.cpp /Fe:DeviceSimulator.exe
DeviceSimulator.exe
cl /c /EHsc main.cpp
```

## Linux (GCC)

```bash
cd labs/01-source-to-executable/starter
g++ main.cpp -o DeviceSimulator
./DeviceSimulator
g++ -c main.cpp -o main.o
```

## Practice

1. Change temperature to 45.0 and recompile.
2. Add a pressure reading and device metadata.
3. Implement NORMAL/WARNING/CRITICAL status boundaries from the chapter.
4. Test compilation without linking, then re-link.

Keep generated `.exe`, `.obj`, `.o`, and other build outputs out of Git (see the repository `.gitignore`).
