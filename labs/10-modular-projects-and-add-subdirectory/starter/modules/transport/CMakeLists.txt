add_library(embeddedcore_transport STATIC transport.cpp)
target_include_directories(embeddedcore_transport PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
target_link_libraries(embeddedcore_transport PUBLIC embeddedcore_options)
