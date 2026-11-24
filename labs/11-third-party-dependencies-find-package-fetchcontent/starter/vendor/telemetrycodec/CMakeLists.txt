cmake_minimum_required(VERSION 3.20)
project(TelemetryCodec VERSION 1.2.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
add_library(telemetrycodec STATIC src/codec.cpp)
add_library(TelemetryCodec::telemetrycodec ALIAS telemetrycodec)
target_compile_features(telemetrycodec PUBLIC cxx_std_17)
target_include_directories(telemetrycodec PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
set_target_properties(telemetrycodec PROPERTIES EXPORT_NAME telemetrycodec)
install(TARGETS telemetrycodec EXPORT TelemetryCodecTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT TelemetryCodecTargets
  NAMESPACE TelemetryCodec::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TelemetryCodec)
configure_package_config_file(
  cmake/TelemetryCodecConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TelemetryCodec)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfigVersion.cmake
  VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/TelemetryCodecConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TelemetryCodec)
