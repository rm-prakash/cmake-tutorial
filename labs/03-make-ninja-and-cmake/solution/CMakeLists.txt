cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter03 LANGUAGES CXX)

add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
)

target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE embeddedcore)
