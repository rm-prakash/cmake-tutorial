add_executable(embeddedcore_contract_test contract_test.cpp)
target_link_libraries(embeddedcore_contract_test PRIVATE EmbeddedCore::Core)
add_test(NAME embeddedcore.contract COMMAND embeddedcore_contract_test)
add_test(NAME devicesimulator.smoke COMMAND DeviceSimulator)
set_tests_properties(devicesimulator.smoke PROPERTIES
  PASS_REGULAR_EXPRESSION "Device status: HEALTHY")
