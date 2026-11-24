cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter12 VERSION 1.0 LANGUAGES CXX)

option(EMBEDDEDCORE_STRICT_WARNINGS "Enable strong compiler warnings" ON)
option(EMBEDDEDCORE_ENABLE_TRACE "Enable internal device diagnostics" OFF)
option(EMBEDDEDCORE_BUILD_TESTS "Build example tests" ON)

# Interface library groups warning policy; it does not create a binary.
add_library(embeddedcore_warnings INTERFACE)
if(EMBEDDEDCORE_STRICT_WARNINGS)
    if(MSVC)
        # Works with MSVC and typically with clang-cl's MSVC-compatible driver.
        target_compile_options(embeddedcore_warnings INTERFACE /W4)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "^(GNU|Clang|AppleClang)$")
        target_compile_options(embeddedcore_warnings INTERFACE -Wall -Wextra -Wpedantic)
    endif()
endif()

# CMake configures using the TARGET platform when cross-compiling.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config/build_info.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/generated/embeddedcore/build_info.hpp"
    @ONLY
)

add_library(embeddedcore STATIC src/sensor.cpp src/diagnostics.cpp)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/generated>"
)
# TODO 1: Attach warning policy to embeddedcore only.
# target_link_libraries(embeddedcore PRIVATE embeddedcore_warnings)
# API level is part of the *public* contract; consumers must see it.
# TODO 2: Publish the public API contract to consumers.
target_compile_definitions(embeddedcore PUBLIC EMBEDDEDCORE_API_LEVEL=2)
# Implementation-only settings are never needed by consumers.
target_compile_definitions(embeddedcore PRIVATE
    "$<$<BOOL:${EMBEDDEDCORE_ENABLE_TRACE}>:EMBEDDEDCORE_INTERNAL_TRACE=1>"
    "$<$<CONFIG:Debug>:EMBEDDEDCORE_DEBUG_BUILD=1>"
    "$<$<CONFIG:Release>:EMBEDDEDCORE_RELEASE_BUILD=1>"
)

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)
target_link_libraries(DeviceSimulator PRIVATE embeddedcore_warnings)
# Configuration-dependent definition only for the app.
target_compile_definitions(DeviceSimulator PRIVATE
    "$<$<CONFIG:Debug>:DEVICE_SIMULATOR_DEBUG=1>"
)

if(EMBEDDEDCORE_BUILD_TESTS)
    include(CTest)
    add_executable(contract_test tests/contract_test.cpp)
    target_link_libraries(contract_test PRIVATE EmbeddedCore::Core)
    target_link_libraries(contract_test PRIVATE embeddedcore_warnings)
    add_test(NAME contract_test COMMAND contract_test)
    add_test(NAME simulator_smoke COMMAND DeviceSimulator)
endif()

# Generator expressions are evaluated during generation, not configure.
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/target-summary-$<CONFIG>.txt"
    CONTENT "config=$<CONFIG>\ncore-api=$<TARGET_PROPERTY:embeddedcore,INTERFACE_COMPILE_DEFINITIONS>\n"
)
