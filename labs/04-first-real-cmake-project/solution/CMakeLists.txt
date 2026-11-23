cmake_minimum_required(VERSION 3.20)

project(EmbeddedCoreChapter04 VERSION 0.1.0 LANGUAGES CXX)

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Source directory: ${PROJECT_SOURCE_DIR}")
message(STATUS "Build directory: ${PROJECT_BINARY_DIR}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Generator: ${CMAKE_GENERATOR}")

add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
)

target_compile_features(embeddedcore PUBLIC cxx_std_17)

target_include_directories(embeddedcore PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(DeviceSimulator app/main.cpp)

target_link_libraries(DeviceSimulator PRIVATE embeddedcore)
