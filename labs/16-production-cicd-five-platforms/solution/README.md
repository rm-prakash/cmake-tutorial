# EmbeddedCore Chapter 16 complete reference solution

The package producer is this directory. The independent consumer is `consumer/`.

Run local Linux native builds with `bash scripts/ci-build.sh linux-x86_64 Debug` and `bash scripts/ci-build.sh linux-x86_64 Release`.

The scripts stage, package, and verify the public educational example. See the chapter textbook for the full release security discussion. Android builds require a compatible NDK, and Windows builds require an initialized x64 MSVC environment.

`Jenkinsfile` is an illustrative Scripted Pipeline whose agent labels must be configured by the Jenkins administrator. `.github/workflows/chapter16-build.yml` sits at the repository root, not here.

The generated `build/`, `build-consumer/` and `out/` folders are transient; do not commit them. No real publication credentials or registry endpoints are included.
