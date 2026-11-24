cmake_minimum_required(VERSION 3.21)
project(EmbeddedCoreChapter14 VERSION 1.0 LANGUAGES CXX)
include(CTest)

set(EMBEDDEDCORE_PROVIDER "fixture" CACHE STRING "fixture or openssl")
set_property(CACHE EMBEDDEDCORE_PROVIDER PROPERTY STRINGS fixture openssl)
set(EMBEDDEDCORE_CRYPTO_PROFILE "standard" CACHE STRING "standard or approved")
set_property(CACHE EMBEDDEDCORE_CRYPTO_PROFILE PROPERTY STRINGS standard approved)
set(EMBEDDEDCORE_ARTIFACT_ROOT "" CACHE PATH "Path to staged, ABI-specific fixture")
set(EMBEDDEDCORE_OPENSSL_ROOT "" CACHE PATH "Pinned OpenSSL install prefix")

include(cmake/TargetIdentity.cmake)
message(STATUS "EmbeddedCore target identity: ${EMBEDDEDCORE_TARGET_ID}")

# Deliberate fail-closed policy: this public teaching repo contains NO approved
# cryptographic provider package or operational compliance evidence.
if(NOT EMBEDDEDCORE_CRYPTO_PROFILE STREQUAL "standard")
  message(FATAL_ERROR
    "CRYPTO PROFILE REJECTED: this demo has no approved provider, provenance, "
    "module configuration, or compliance evidence. Do not fall back to standard.")
endif()

if(EMBEDDEDCORE_PROVIDER STREQUAL "fixture")
  include(cmake/ResolveFixture.cmake)
  embeddedcore_resolve_fixture()
  set(_dependency TelemetryCodec::TelemetryCodec)
elseif(EMBEDDEDCORE_PROVIDER STREQUAL "openssl")
  include(cmake/ResolveOpenSSL.cmake)
  embeddedcore_resolve_openssl()
  set(_dependency OpenSSL::Crypto)
else()
  message(FATAL_ERROR "Unknown EMBEDDEDCORE_PROVIDER=${EMBEDDEDCORE_PROVIDER}")
endif()

add_library(embeddedcore STATIC src/core.cpp)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(embeddedcore PRIVATE ${_dependency})
if(EMBEDDEDCORE_PROVIDER STREQUAL "fixture")
  target_compile_definitions(embeddedcore PRIVATE EMBEDDEDCORE_USE_FIXTURE=1)
else()
  target_compile_definitions(embeddedcore PRIVATE EMBEDDEDCORE_USE_OPENSSL=1)
endif()

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)

if(BUILD_TESTING)
  add_executable(core_test tests/core_test.cpp)
  target_link_libraries(core_test PRIVATE EmbeddedCore::Core)
  add_test(NAME core_contract COMMAND core_test)
endif()
