#!/usr/bin/env python3
TARGETS=('windows-x64','linux-x86_64','android-armeabi-v7a','android-arm64-v8a','android-x86_64')
assert len(set(TARGETS))==5
for target in TARGETS:
  for config in ('Debug','Release'): print(target,config)
