$ErrorActionPreference = 'Stop'
if (-not $env:ANDROID_NDK_HOME) { throw 'Set ANDROID_NDK_HOME to your installed NDK directory' }
$toolchain = Join-Path $env:ANDROID_NDK_HOME 'build/cmake/android.toolchain.cmake'
if (-not (Test-Path $toolchain)) { throw "NDK toolchain not found: $toolchain" }
$sourceDir = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$api = if ($env:ANDROID_API_LEVEL) { $env:ANDROID_API_LEVEL } else { '24' }
foreach ($abi in @('armeabi-v7a', 'arm64-v8a', 'x86_64')) {
    $buildDir = Join-Path $sourceDir "build/android/$abi"
    cmake -S $sourceDir -B $buildDir -G Ninja "-DCMAKE_TOOLCHAIN_FILE=$toolchain" "-DANDROID_ABI=$abi" "-DANDROID_PLATFORM=android-$api" '-DCMAKE_BUILD_TYPE=Release' '-DBUILD_TESTING=OFF'
    if ($LASTEXITCODE -ne 0) { throw "Configure failed for $abi" }
    cmake --build $buildDir --parallel
    if ($LASTEXITCODE -ne 0) { throw "Build failed for $abi" }
    cmake --install $buildDir --prefix (Join-Path $sourceDir "stage/android/$abi")
    if ($LASTEXITCODE -ne 0) { throw "Install failed for $abi" }
}
