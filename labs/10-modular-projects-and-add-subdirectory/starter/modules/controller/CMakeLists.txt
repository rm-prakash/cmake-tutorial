add_library(embeddedcore_controller STATIC controller.cpp)
target_include_directories(embeddedcore_controller PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
target_link_libraries(embeddedcore_controller
  PUBLIC embeddedcore_sensors embeddedcore_options
  PRIVATE embeddedcore_diagnostics embeddedcore_transport)
