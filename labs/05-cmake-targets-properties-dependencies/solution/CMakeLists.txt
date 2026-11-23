cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter05 VERSION 0.2.0 LANGUAGES CXX)

include(CTest)

# Header-only configuration target: no archive is generated.
add_library(embeddedcore_config INTERFACE)
target_compile_features(embeddedcore_config INTERFACE cxx_std_17)

# The simulated device kernel is a compiled library.
add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
)

# Demonstrates stable names for other targets in the same build.
add_library(EmbeddedCore::Core ALIAS embeddedcore)

target_include_directories(embeddedcore PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_link_libraries(embeddedcore PUBLIC embeddedcore_config)

target_compile_definitions(embeddedcore PRIVATE
    EMBEDDEDCORE_STRICT_LIMIT
)

# Scoped, compiler-specific warnings (our own C++ source only).
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

# Inspect only after properties were assigned.
get_target_property(_incs embeddedcore INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(_links embeddedcore INTERFACE_LINK_LIBRARIES)
get_target_property(_defs embeddedcore COMPILE_DEFINITIONS)
message(STATUS "Public include dirs: ${_incs}")
message(STATUS "Public link interface: ${_links}")
message(STATUS "Own compile definitions: ${_defs}")
