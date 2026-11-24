cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter10 VERSION 1.0.0 LANGUAGES CXX)

option(EMBEDDEDCORE_BUILD_TESTS "Build EmbeddedCore tests" ON)
option(EMBEDDEDCORE_ENABLE_WARNINGS "Enable extra compiler warnings" ON)

# Target-level configuration; an INTERFACE target builds no binary.
add_library(embeddedcore_options INTERFACE)
target_compile_features(embeddedcore_options INTERFACE cxx_std_17)
if(EMBEDDEDCORE_ENABLE_WARNINGS)
  if(MSVC)
    target_compile_options(embeddedcore_options INTERFACE /W4)
  else()
    target_compile_options(embeddedcore_options INTERFACE -Wall -Wextra -Wpedantic)
  endif()
endif()

add_subdirectory(modules/sensors)
add_subdirectory(modules/diagnostics)
add_subdirectory(modules/transport)
add_subdirectory(modules/controller)

# Umbrella target is a convenient API entry point for the consumer.
add_library(embeddedcore INTERFACE)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_link_libraries(embeddedcore INTERFACE embeddedcore_controller)

add_subdirectory(app)
if(EMBEDDEDCORE_BUILD_TESTS)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(tests)
  endif()
endif()
