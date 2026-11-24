# Chapter 16 hands-on lab

## Linux x86-64

```bash
cd labs/16-production-cicd-five-platforms/solution
bash scripts/ci-build.sh linux-x86_64 Debug
bash scripts/ci-build.sh linux-x86_64 Release
```

## Windows x64

Open a VS 2019 x64 Native Tools Command Prompt with CMake, Ninja and Python on `PATH`.

```powershell
./scripts/ci-build.ps1 -Target windows-x64 -Config Debug
./scripts/ci-build.ps1 -Target windows-x64 -Config Release
```

## Android NDK

Set `ANDROID_NDK_HOME` to the NDK installation directory. On an environment with Android dependencies installed:

```bash
bash scripts/ci-build.sh android-armeabi-v7a Release
bash scripts/ci-build.sh android-arm64-v8a Release
bash scripts/ci-build.sh android-x86_64 Release
```

Android labs compile libraries and link an independent consumer but **do not execute Android binaries**. To run tests, add a compatible emulator/device and appropriate test deployment infrastructure.

## Package verification

```bash
python3 scripts/verify-package.py \
  out/artifacts/embeddedcore-2.0.0-linux-x86_64-release.tar.gz \
  out/artifacts/embeddedcore-2.0.0-linux-x86_64-release.json \
  out/artifacts/embeddedcore-2.0.0-linux-x86_64-release.sha256
```

All targets are isolated in separate build directories. The package archive contains install-tree files, not build-tree files. No external artifact-repository credentials or private dependencies are included.
