# add_subdirectory() introduces a child directory variable scope.
message(STATUS "Child inherited label: ${DEVICE_LABEL}")
set(DEVICE_LABEL "child-local-value")
message(STATUS "Child modified label: ${DEVICE_LABEL}")
