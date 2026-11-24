add_library(embeddedcore_sensors STATIC sensor.cpp)
target_include_directories(embeddedcore_sensors PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
target_link_libraries(embeddedcore_sensors PUBLIC embeddedcore_options)
