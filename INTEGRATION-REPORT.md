# Repository integration and validation report

## Consolidation

- **Chapters:** 16 complete Markdown lessons, indexed from the course homepage
- **Lab directories:** 16, with source projects and learning exercises
- **Workflow files:** 16 GitHub Actions YAML files
- **Collisions when assembling chapter packages:** none
- **Fixed five outdated inter-chapter links:** docs/INTEGRATION-REPORT.md, chapters/06-variables-scopes-and-include-directories/README.md, chapters/03-make-ninja-and-cmake/README.md, chapters/08-static-shared-libraries-binary-compatibility/README.md, chapters/05-cmake-targets-properties-dependencies/README.md, chapters/09-runtime-dependencies-and-deployment/README.md
- **Unresolved local Markdown links:** 0
- **Workflow YAML parser errors:** 0

## Linux build verification (performed on this consolidated repository)

CMake 3.31, Ninja, GCC 14.2 were used for the local checks. Build directories were created outside the repository.

- **Chapters 3–10:** configured, built, and CTest passed in Debug using Ninja.
- **Chapter 11:** configured in its intended `EMBEDDEDCORE_DEPENDENCY_MODE=FETCH` mode, built, and CTest passed. A bare default configure fails until TelemetryCodec is installed, which is an expected prerequisite for package mode.
- **Chapters 12–13:** configured, built, and CTest passed.
- **Chapter 14:** configured with `EMBEDDEDCORE_PROVIDER=openssl`, built, and CTest passed. Fixture mode requires its fixture-building step.
- **Chapters 15–16:** configured, built, and CTest passed for the native Linux solution.
- **Chapters 1–2:** manual compiler/archiver labs, not CMake configure projects; not retested during this consolidation.

All **14 of 14** Chapter 3–16 solution projects passed a supported Linux configuration, build, and CTest run. This is a basic smoke test, not validation of every tutorial experiment or delivery scenario.

## Not verified in this environment

- Microsoft Visual C++ builds on Windows and GitHub Actions hosted jobs
- Android ARMv7, ARM64, or x86-64 NDK builds, emulator execution, or native tests
- Jenkins pipeline execution and live artifact-repository publication
- Full packaging/relocatability and failure-injection exercises for every chapter
- All student starter exercises (many intentionally require completing TODOs)

## Publication checklist

Before releasing publicly, choose explicit licenses for original prose and code; review all code and images for third-party rights; test Windows and Android CI on target runners; inspect GitHub workflow permissions; and confirm no private credentials or internal artifact URLs have been included.
