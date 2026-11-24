cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter13 VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CTest)

# The NDK supplies its own platform-aware toolchain file; do not override compilers here.
if(ANDROID)
    set(_expected_android_abis armeabi-v7a arm64-v8a x86_64)
    if(NOT ANDROID_ABI IN_LIST _expected_android_abis)
        message(FATAL_ERROR "This course lab supports Android ABIs: ${_expected_android_abis}; received '${ANDROID_ABI}'")
    endif()
    set(EMBEDDEDCORE_TARGET_ABI "${ANDROID_ABI}")
else()
    set(EMBEDDEDCORE_TARGET_ABI "${CMAKE_SYSTEM_PROCESSOR}")
endif()

message(STATUS "Host: ${CMAKE_HOST_SYSTEM_NAME}/${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "Target: ${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Target ABI label: ${EMBEDDEDCORE_TARGET_ABI}")
message(STATUS "Cross compiling flag: ${CMAKE_CROSSCOMPILING}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")

# This header is generated separately for each target build directory.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config/target_config.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/generated/embeddedcore/target_config.hpp"
    @ONLY
)

add_library(embeddedcore STATIC src/sensor.cpp src/platform_report.cpp)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/generated>"
)
set_target_properties(embeddedcore PROPERTIES OUTPUT_NAME embeddedcore)

# Android cross-compilation produces a library; running Android binaries requires a device/emulator.
if(NOT ANDROID AND NOT CMAKE_CROSSCOMPILING)
    add_executable(DeviceSimulator app/main.cpp)
    target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)
    if(BUILD_TESTING)
        add_executable(embeddedcore_tests tests/contract_test.cpp)
        target_link_libraries(embeddedcore_tests PRIVATE EmbeddedCore::Core)
        add_test(NAME embeddedcore_contract COMMAND embeddedcore_tests)
    endif()
endif()

install(TARGETS embeddedcore ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(DIRECTORY include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/generated/embeddedcore/target_config.hpp"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/embeddedcore")
