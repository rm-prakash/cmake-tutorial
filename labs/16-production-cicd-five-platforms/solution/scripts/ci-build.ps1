param([ValidateSet('windows-x64')][string]$Target='windows-x64',
      [ValidateSet('Debug','Release')][string]$Config='Release')
$ErrorActionPreference='Stop'
$root=(Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$build=Join-Path $root "build/$Target/$Config"
$stage=Join-Path $root "out/stage/$Target/$Config"
$consumer=Join-Path $root "build-consumer/$Target/$Config"
function Invoke-Checked([string]$Tool,[string[]]$Arguments) {
  & $Tool @Arguments
  if ($LASTEXITCODE -ne 0) { throw "Failed: $Tool" }
}
# Requires x64 MSVC developer environment and Ninja available on PATH.
Invoke-Checked cmake @('-S',$root,'-B',$build,'-G','Ninja',"-DCMAKE_BUILD_TYPE=$Config")
Invoke-Checked cmake @('--build',$build,'--parallel')
Invoke-Checked ctest @('--test-dir',$build,'--output-on-failure','--output-junit',(Join-Path $build 'producer-junit.xml'))
Invoke-Checked cmake @('--install',$build,'--prefix',$stage)
Invoke-Checked cmake @('-S',(Join-Path $root 'consumer'),'-B',$consumer,'-G','Ninja',"-DCMAKE_BUILD_TYPE=$Config","-DCMAKE_PREFIX_PATH=$stage")
Invoke-Checked cmake @('--build',$consumer,'--parallel')
Invoke-Checked ctest @('--test-dir',$consumer,'--output-on-failure','--output-junit',(Join-Path $consumer 'consumer-junit.xml'))
Invoke-Checked python @((Join-Path $root 'scripts/package.py'),$stage,(Join-Path $root 'out/artifacts'),$Target,$Config)
