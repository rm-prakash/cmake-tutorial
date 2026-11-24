cmake_minimum_required(VERSION 3.23)
project(EmbeddedCore VERSION 2.0.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CTest)
option(EMBEDDEDCORE_REQUIRE_APPROVED_CRYPTO "Use approved crypto profile" OFF)
if(EMBEDDEDCORE_REQUIRE_APPROVED_CRYPTO)
  message(FATAL_ERROR "Public lab has no approved crypto artifacts. No fallback permitted.")
endif()
add_library(embeddedcore STATIC src/sensor.cpp)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
set_target_properties(embeddedcore PROPERTIES EXPORT_NAME Core)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
if(BUILD_TESTING AND NOT CMAKE_CROSSCOMPILING)
  add_executable(sensor_test tests/sensor_test.cpp)
  target_link_libraries(sensor_test PRIVATE EmbeddedCore::Core)
  add_test(NAME sensor_contract COMMAND sensor_test)
endif()
install(TARGETS embeddedcore EXPORT EmbeddedCoreTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
set(pkgdir "${CMAKE_INSTALL_LIBDIR}/cmake/EmbeddedCore")
configure_package_config_file(cmake/EmbeddedCoreConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfig.cmake"
  INSTALL_DESTINATION "${pkgdir}")
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfigVersion.cmake"
  VERSION "${PROJECT_VERSION}" COMPATIBILITY SameMajorVersion)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/EmbeddedCoreConfigVersion.cmake" DESTINATION "${pkgdir}")
install(EXPORT EmbeddedCoreTargets FILE EmbeddedCoreTargets.cmake
  NAMESPACE EmbeddedCore:: DESTINATION "${pkgdir}")
