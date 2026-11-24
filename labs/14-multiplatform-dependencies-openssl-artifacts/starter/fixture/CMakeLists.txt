cmake_minimum_required(VERSION 3.21)
project(TelemetryCodecFixture VERSION 1.0 LANGUAGES CXX)
add_library(telemetrycodec STATIC src/codec.cpp)
target_compile_features(telemetrycodec PUBLIC cxx_std_17)
target_include_directories(telemetrycodec PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>")
install(TARGETS telemetrycodec ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
