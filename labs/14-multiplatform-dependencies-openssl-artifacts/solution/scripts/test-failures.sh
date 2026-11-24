#!/usr/bin/env bash
set -euo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
fixture="$root/artifacts/linux-x86_64"
if [[ ! -f "$fixture/metadata/target-id.txt" ]]; then
  echo "Run scripts/build-fixture.sh first" >&2
  exit 1
fi
expect_failure() {
  local label="$1"; shift
  echo "TEST: $label"
  if "$@" > "$root/build/negative-${label}.log" 2>&1; then
    echo "ERROR: invalid scenario unexpectedly succeeded" >&2
    exit 1
  fi
  echo "PASS: $label rejected (see build/negative-${label}.log)"
}
mkdir -p "$root/build"
backup="$(mktemp -d)"
trap 'cp "$backup/target-id.txt" "$fixture/metadata/target-id.txt"; cp "$backup/libtelemetrycodec.a" "$fixture/lib/libtelemetrycodec.a"; rm -rf "$backup"' EXIT
cp "$fixture/metadata/target-id.txt" "$backup/target-id.txt"
cp "$fixture/lib/libtelemetrycodec.a" "$backup/libtelemetrycodec.a"
# Separately configured trees prevent cached success from hiding a failure.
printf 'android-arm64-v8a\n' > "$fixture/metadata/target-id.txt"
expect_failure wrong-abi cmake -S "$root" -B "$root/build/negative-wrong-abi" -G Ninja -DEMBEDDEDCORE_PROVIDER=fixture -DEMBEDDEDCORE_ARTIFACT_ROOT="$fixture"
cp "$backup/target-id.txt" "$fixture/metadata/target-id.txt"
printf '\ncorruption\n' >> "$fixture/lib/libtelemetrycodec.a"
expect_failure corrupt-hash cmake -S "$root" -B "$root/build/negative-corrupt-hash" -G Ninja -DEMBEDDEDCORE_PROVIDER=fixture -DEMBEDDEDCORE_ARTIFACT_ROOT="$fixture"
cp "$backup/libtelemetrycodec.a" "$fixture/lib/libtelemetrycodec.a"
expect_failure unapproved-profile cmake -S "$root" -B "$root/build/negative-unapproved-profile" -G Ninja -DEMBEDDEDCORE_CRYPTO_PROFILE=approved
