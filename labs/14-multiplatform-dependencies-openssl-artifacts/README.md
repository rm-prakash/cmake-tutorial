# Chapter 14 Lab — Dependency Selection, Verification, and OpenSSL

This lab has a **starter** and a **solution**. Follow the textbook at `chapters/14-multiplatform-dependencies-openssl-artifacts/README.md`.

## Linux — validated solution

```bash
cd labs/14-multiplatform-dependencies-openssl-artifacts/solution
bash scripts/build-fixture.sh
cmake --preset linux-fixture
cmake --build --preset linux-fixture
ctest --preset linux-fixture
./build/linux-fixture/DeviceSimulator
cmake --preset linux-openssl
cmake --build --preset linux-openssl
ctest --preset linux-openssl
./build/linux-openssl/DeviceSimulator
bash scripts/test-failures.sh
```

The OpenSSL variant needs native development headers and link libraries. Negative tests are **expected to fail during configuration**; the test harness reports success only when the failures are observed.

## Windows MSVC + Ninja (not locally executed)

Use **x64 Native Tools Command Prompt** or an equivalent configured PowerShell session, then:

```powershell
cd labs/14-multiplatform-dependencies-openssl-artifacts/solution
.\scripts\build-fixture.ps1
cmake --preset windows-fixture
cmake --build --preset windows-fixture
ctest --preset windows-fixture
.\build\windows-fixture\DeviceSimulator.exe
```

## Student progression

1. Read the chapter and inspect `starter/CMakeLists.txt` TODOs.
2. Recreate the provider policy and imported target integration.
3. Stage a native fixture and verify its identity and SHA-256.
4. Compile and test the consumer.
5. Implement a second dependency mode using `OpenSSL::Crypto`.
6. Verify **negative** cases: wrong ABI, changed archive, unapproved profile.
7. Compare with the `solution/` folder and complete assignments.

No real FIPS package or proprietary repository is included. The `approved` profile is deliberately rejected in this teaching lab.
