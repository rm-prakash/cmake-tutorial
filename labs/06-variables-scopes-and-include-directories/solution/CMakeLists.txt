cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter06 VERSION 0.3.0 LANGUAGES CXX)
include(CTest)

# User-configurable cache entries.
set(DEVICE_LABEL "SensorNode-A" CACHE STRING "Simulated device identifier")
option(EMBEDDEDCORE_STRICT_LIMIT "Warn above 35C rather than 40C" ON)
option(EMBEDDEDCORE_SHOW_SCOPE_DEMO "Display variable-scope examples" ON)

if(NOT DEVICE_LABEL MATCHES "^[A-Za-z0-9_-]+$")
    message(FATAL_ERROR "DEVICE_LABEL must contain only letters, digits, _ or -")
endif()

if(EMBEDDEDCORE_STRICT_LIMIT)
    set(WARNING_THRESHOLD_C 35.0)
else()
    set(WARNING_THRESHOLD_C 40.0)
endif()

# Generate a header in the build tree, never the source tree.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config/device_config.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/generated/embeddedcore/device_config.hpp"
    @ONLY
)

add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
    src/device_info.cpp
)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/generated"
)
if(MSVC)
    target_compile_options(embeddedcore PRIVATE /W4)
else()
    target_compile_options(embeddedcore PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)

if(BUILD_TESTING)
    add_executable(embeddedcore_contract_test tests/contract_test.cpp)
    target_link_libraries(embeddedcore_contract_test PRIVATE EmbeddedCore::Core)
    add_test(NAME EmbeddedCoreContract COMMAND embeddedcore_contract_test)
endif()

if(EMBEDDEDCORE_SHOW_SCOPE_DEMO)
    set(SCOPE_MESSAGE "set in parent directory")
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ScopeExamples.cmake")
    message(STATUS "After include: ${INCLUDED_NOTE}")
    demonstrate_function_scope()
    message(STATUS "After function: ${SCOPE_MESSAGE}")
    publish_to_caller(PUBLISHED_NOTE)
    message(STATUS "After PARENT_SCOPE: ${PUBLISHED_NOTE}")
    add_subdirectory(scope_child)
    message(STATUS "After add_subdirectory: ${DEVICE_LABEL}")
endif()
message(STATUS "Device label: ${DEVICE_LABEL}")
message(STATUS "Threshold: ${WARNING_THRESHOLD_C} C")
