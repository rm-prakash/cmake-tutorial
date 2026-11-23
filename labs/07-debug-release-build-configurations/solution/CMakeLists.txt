cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter07 VERSION 0.4.0 LANGUAGES CXX)
include(CTest)

# Same source target for every build configuration.
add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# The definition is applied to the library AND its consumers so that
# the diagnostic helper (compiled in the app/test) reports the same config.
# We use no custom optimization flags: CMake's Debug/Release defaults remain intact.
target_compile_definitions(embeddedcore PUBLIC
    "$<$<CONFIG:Debug>:EMBEDDEDCORE_DEBUG_BUILD=1>"
    "$<$<CONFIG:Release>:EMBEDDEDCORE_RELEASE_BUILD=1>"
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

    add_executable(configuration_test tests/configuration_test.cpp)
    target_link_libraries(configuration_test PRIVATE EmbeddedCore::Core)
    add_test(NAME BuildConfigurationContract COMMAND configuration_test)
endif()

message(STATUS "Generator: ${CMAKE_GENERATOR}")
if(CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Multi-config: ${CMAKE_CONFIGURATION_TYPES}")
else()
    message(STATUS "Single-config type: ${CMAKE_BUILD_TYPE}")
endif()
