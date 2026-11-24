$ErrorActionPreference = 'Stop'
$root = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$targetId = 'windows-x64'
$stage = Join-Path $root "artifacts/$targetId"
cmake -S (Join-Path $root 'fixture') -B (Join-Path $root 'build/fixture/windows-x64') -G Ninja -DCMAKE_BUILD_TYPE=Debug "-DCMAKE_INSTALL_PREFIX=$stage"
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
cmake --build (Join-Path $root 'build/fixture/windows-x64')
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
cmake --install (Join-Path $root 'build/fixture/windows-x64')
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
cmake "-DROOT=$stage" "-DTARGET_ID=$targetId" '-DLIB_NAME=telemetrycodec.lib' -P (Join-Path $root 'scripts/write-manifest.cmake')
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
