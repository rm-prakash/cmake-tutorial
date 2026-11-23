# Student starter — Chapter 07

This starter builds, but you must complete two investigations independently:

1. Replace the three target_compile_definitions lines in CMakeLists.txt with equivalent expressions you can explain; determine why PUBLIC (not PRIVATE) is required by configuration_test.cpp.
2. Add a custom build configuration named RelWithDebInfo using a fresh Ninja build directory. Record its observed configuration string and compile flags; explain the distinction between RelWithDebInfo and Release.

Compare your results with the solution folder and the textbook. For reproducibility, do not hard-code -O0 or -O3 into target_compile_options.
