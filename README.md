# Modern CMake: From First Principles to Production CI/CD

A free, university-style CMake course, taught through an evolving, fictional embedded-device project: **EmbeddedCore** (library) and **DeviceSimulator** (application). No proprietary source code or private infrastructure is required.

> **Status:** Chapter 1 is written and includes a runnable lab. Chapters 2–16 are planned, not yet authored.

## Start here

1. [Course syllabus](COURSE-SYLLABUS.md)
2. [Chapter 01 — How C++ Source Becomes an Executable: Building DeviceSimulator](chapters/01-source-to-executable/README.md)
3. [Chapter 01 runnable lab](labs/01-source-to-executable/README.md)
4. [Chapter 01 quiz solutions](solutions/01-source-to-executable/quiz-answers.md)

## Course modules

| Module | Chapters | Focus |
| --- | --- | --- |
| I | 01–04 | Source, compiler/linker, build systems, first CMake project |
| II | 05–08 | CMake targets, variables, configurations, static/shared libraries |
| III | 09–12 | DLL deployment, modular projects, dependencies, compiler settings |
| IV | 13–16 | Cross-compilation, dependencies, packages, CI/CD |

## Repository organization

- `chapters/` — textbook chapters and conceptual explanations.
- `labs/` — standalone runnable starter source and exercises.
- `solutions/` — separate answers and completed exercises.
- `capstone/` — the eventual portable EmbeddedCore library and consumer project.
- `assets/` — original diagrams and supporting illustrations.
- `docs/` — shared glossary, prerequisites, and troubleshooting.
- `.github/workflows/` — automated checks as course labs grow.

## How to contribute

Open an issue to report unclear explanations or broken commands. When adding a new chapter, keep theoretical explanations in Markdown and provide full source files under `labs/`. Avoid machine-specific absolute paths in runnable examples except where explicitly marked as illustrative.

## Licensing

**License not selected yet.** Before publicly releasing this repository, choose a license for the prose (for example, CC BY 4.0) and one for sample code (for example, MIT), if you want reuse under those terms. Do not add a license without reviewing its implications.
