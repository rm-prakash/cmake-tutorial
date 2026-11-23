# Chapter 2 — Knowledge Check Answers

1. `#include` causes the preprocessor to incorporate the referenced header's preprocessing tokens/content for compilation.
2. The compiler sees a declaration specifying the function interface; the final definition is resolved by the linker from another object/library.
3. An object file is one compiled translation unit; a static library usually collects multiple object files for later linking.
4. The linker, when it cannot find a matching definition.
5. `/c` compiles only and suppresses the final link step.
6. Traditional GNU static archive processing resolves symbols at the point where an archive is encountered; place the referencing object/input earlier in the link line.
7. Static archive creation does not automatically perform a final link or recursively merge dependent archives.
8. The shared binary may be missing or outside the loader's search paths at runtime.
9. A header provides declarations to compile against; the linker still requires compiled definitions when functions are referenced.
10. A build system tracks targets, source dependencies, compiler flags, and changed files, avoiding manual command coordination.
