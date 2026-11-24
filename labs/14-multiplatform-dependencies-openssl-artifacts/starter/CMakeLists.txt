cmake_minimum_required(VERSION 3.21)
project(EmbeddedCoreChapter14Starter LANGUAGES CXX)
include(CTest)
set(EMBEDDEDCORE_PROVIDER "fixture" CACHE STRING "fixture or openssl")
set(EMBEDDEDCORE_CRYPTO_PROFILE "standard" CACHE STRING "standard or approved")
set(EMBEDDEDCORE_ARTIFACT_ROOT "" CACHE PATH "ABI-specific package root")
include(cmake/TargetIdentity.cmake)

# TODO 1: reject any crypto profile that this public lab cannot verify.
# TODO 2: if provider=fixture, include ResolveFixture and call its resolver.
# TODO 3: if provider=openssl, include ResolveOpenSSL and call its resolver.
# TODO 4: select a target dependency, add embeddedcore, and link PRIVATE.
# TODO 5: set EMBEDDEDCORE_USE_FIXTURE or EMBEDDEDCORE_USE_OPENSSL.
# TODO 6: add DeviceSimulator and core_test; register the CTest test.
# Compare the solution only after attempting these tasks.
