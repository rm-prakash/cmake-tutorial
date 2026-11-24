cmake_minimum_required(VERSION 3.21)
project(EmbeddedCoreChapter09Starter LANGUAGES CXX)
include(GNUInstallDirs)
include(CTest)

add_library(device_transport SHARED src/transport.cpp)
target_compile_definitions(device_transport PRIVATE DEVICE_TRANSPORT_BUILDING)
target_include_directories(device_transport PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(embeddedcore SHARED src/core.cpp)
target_compile_definitions(embeddedcore PRIVATE EMBEDDEDCORE_BUILDING)
target_include_directories(embeddedcore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(embeddedcore PRIVATE device_transport)

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE embeddedcore)

# LAB TODO 1: Add Windows POST_BUILD runtime DLL copying.
# LAB TODO 2: Add Linux executable and shared-library INSTALL_RPATH.
# LAB TODO 3: Install all three targets into bin/lib by artifact type.
# LAB TODO 4: Add CTest device-smoke test.
