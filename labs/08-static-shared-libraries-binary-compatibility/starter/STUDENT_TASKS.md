# Chapter 8 student tasks

The starter is runnable and intentionally contains a working reference baseline. Before opening the solution, experiment by:

1. Building STATIC and SHARED in separate build directories.
2. Removing the Windows DLL-copy step, explaining the loader error and restoring it.
3. Removing the shared PIC property from `embeddedcore_support`, observing what happens on Linux x86-64.
4. Temporarily replacing PRIVATE with PUBLIC on the internal support dependency; inspect the link command and explain the interface change.
5. Testing Ninja Multi-Config with Debug and Release.
6. Explaining why `embeddedcore_support` is not an appropriate part of the public EmbeddedCore API.
