cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter06 VERSION 0.3.0 LANGUAGES CXX)
include(CTest)

set(DEVICE_LABEL "SensorNode-A" CACHE STRING "Simulated device identifier")
option(EMBEDDEDCORE_STRICT_LIMIT "Warn above 35C rather than 40C" ON)

# TODO 1: Set WARNING_THRESHOLD_C based on EMBEDDEDCORE_STRICT_LIMIT.
# TODO 2: Call configure_file on config/device_config.hpp.in with @ONLY.
#         Generated header destination:
#         ${CMAKE_CURRENT_BINARY_DIR}/generated/embeddedcore/device_config.hpp

add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
    src/device_info.cpp
)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)

# TODO 3: Add PUBLIC source include and PRIVATE generated include directories.

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)

if(BUILD_TESTING)
    add_executable(embeddedcore_contract_test tests/contract_test.cpp)
    target_link_libraries(embeddedcore_contract_test PRIVATE EmbeddedCore::Core)
    add_test(NAME EmbeddedCoreContract COMMAND embeddedcore_contract_test)
endif()

# TODO 4: Include cmake/ScopeExamples.cmake and investigate function scope.
