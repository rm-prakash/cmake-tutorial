cmake_minimum_required(VERSION 3.23)
project(EmbeddedCore VERSION 1.4.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CTest)
option(EMBEDDEDCORE_WITH_TELEMETRY "Use installed TelemetryCodec package" OFF)

if(EMBEDDEDCORE_WITH_TELEMETRY)
  find_package(TelemetryCodec 1.2 CONFIG REQUIRED)
endif()

add_library(embeddedcore STATIC src/sensor.cpp src/diagnostics.cpp)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
set_target_properties(embeddedcore PROPERTIES EXPORT_NAME Core)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
if(EMBEDDEDCORE_WITH_TELEMETRY)
  target_link_libraries(embeddedcore PUBLIC TelemetryCodec::TelemetryCodec)
  target_compile_definitions(embeddedcore PRIVATE EMBEDDEDCORE_WITH_TELEMETRY=1)
endif()

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)
if(BUILD_TESTING)
  add_executable(embeddedcore_contract tests/contract.cpp)
  target_link_libraries(embeddedcore_contract PRIVATE EmbeddedCore::Core)
  add_test(NAME embeddedcore_contract COMMAND embeddedcore_contract)
  add_test(NAME simulator_smoke COMMAND DeviceSimulator)
  set_tests_properties(simulator_smoke PROPERTIES PASS_REGULAR_EXPRESSION "Device status: HEALTHY")
endif()

install(TARGETS embeddedcore EXPORT EmbeddedCoreTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
set(EMBEDDEDCORE_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/EmbeddedCore")
configure_package_config_file(
  cmake/EmbeddedCoreConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfig.cmake"
  INSTALL_DESTINATION "${EMBEDDEDCORE_INSTALL_CMAKEDIR}")
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfigVersion.cmake"
  VERSION "${PROJECT_VERSION}" COMPATIBILITY SameMajorVersion)
install(EXPORT EmbeddedCoreTargets
  FILE EmbeddedCoreTargets.cmake
  NAMESPACE EmbeddedCore::
  DESTINATION "${EMBEDDEDCORE_INSTALL_CMAKEDIR}")
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfigVersion.cmake"
  DESTINATION "${EMBEDDEDCORE_INSTALL_CMAKEDIR}")
