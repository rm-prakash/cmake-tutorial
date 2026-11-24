cmake_minimum_required(VERSION 3.21)
project(EmbeddedCoreChapter09 VERSION 1.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(CTest)

# Relative runtime paths make build-tree ELF binaries relocatable.
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)

add_library(device_transport SHARED src/transport.cpp)
target_compile_features(device_transport PUBLIC cxx_std_17)
target_compile_definitions(device_transport PRIVATE DEVICE_TRANSPORT_BUILDING)
target_include_directories(device_transport PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

add_library(embeddedcore SHARED src/core.cpp)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_compile_definitions(embeddedcore PRIVATE EMBEDDEDCORE_BUILDING)
target_include_directories(embeddedcore PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_libraries(embeddedcore PRIVATE device_transport)

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE embeddedcore)

# CMake 3.21+: copy known dependent target DLLs to the build-tree exe folder.
# Unlike LD_LIBRARY_PATH, this does not require users to set environment variables.
if(WIN32)
  add_custom_command(TARGET DeviceSimulator POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
      $<TARGET_RUNTIME_DLLS:DeviceSimulator> "$<TARGET_FILE_DIR:DeviceSimulator>"
    COMMAND_EXPAND_LISTS
    VERBATIM)
endif()

# ELF loader searches relative to each consuming binary / shared library.
if(UNIX AND NOT APPLE)
  set_target_properties(DeviceSimulator PROPERTIES
    INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
  set_target_properties(embeddedcore PROPERTIES INSTALL_RPATH "$ORIGIN")
endif()

install(TARGETS DeviceSimulator embeddedcore device_transport
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(DIRECTORY include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

if(BUILD_TESTING)
  add_test(NAME device-smoke COMMAND DeviceSimulator)
  set_tests_properties(device-smoke PROPERTIES
    PASS_REGULAR_EXPRESSION "Communication: CONNECTED")
endif()
