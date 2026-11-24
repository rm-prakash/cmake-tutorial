add_library(embeddedcore_diagnostics STATIC diagnostics.cpp)
target_include_directories(embeddedcore_diagnostics PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
target_link_libraries(embeddedcore_diagnostics PUBLIC embeddedcore_options)
