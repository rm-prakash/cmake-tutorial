cmake_minimum_required(VERSION 3.23)
project(TelemetryCodec VERSION 1.2.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
add_library(telemetrycodec STATIC src/codec.cpp)
add_library(TelemetryCodec::TelemetryCodec ALIAS telemetrycodec)
set_target_properties(telemetrycodec PROPERTIES EXPORT_NAME TelemetryCodec)
target_compile_features(telemetrycodec PUBLIC cxx_std_17)
target_include_directories(telemetrycodec PUBLIC
 "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
 "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
install(TARGETS telemetrycodec EXPORT TelemetryCodecTargets
 ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
set(_dest "${CMAKE_INSTALL_LIBDIR}/cmake/TelemetryCodec")
configure_package_config_file(cmake/TelemetryCodecConfig.cmake.in
 "${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfig.cmake" INSTALL_DESTINATION "${_dest}")
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfigVersion.cmake"
 VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(EXPORT TelemetryCodecTargets FILE TelemetryCodecTargets.cmake
 NAMESPACE TelemetryCodec:: DESTINATION "${_dest}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfig.cmake"
 "${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfigVersion.cmake" DESTINATION "${_dest}")
