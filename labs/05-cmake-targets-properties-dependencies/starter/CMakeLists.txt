cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter05 LANGUAGES CXX)

include(CTest)

add_library(embeddedcore STATIC
    src/sensor.cpp
    src/diagnostics.cpp
)

# TODO 1: add an INTERFACE target named embeddedcore_config
# TODO 2: set cxx_std_17 as its INTERFACE compile feature
# TODO 3: declare include/ as a PUBLIC include directory on embeddedcore
# TODO 4: link embeddedcore_config PUBLIC to embeddedcore
# TODO 5: define EMBEDDEDCORE_STRICT_LIMIT PRIVATE on embeddedcore
# TODO 6: create the alias EmbeddedCore::Core
# TODO 7: add compiler-specific warnings to embeddedcore only

add_executable(DeviceSimulator app/main.cpp)
# TODO 8: link DeviceSimulator PRIVATE to EmbeddedCore::Core

if(BUILD_TESTING)
    add_executable(embeddedcore_contract_test tests/contract_test.cpp)
    # TODO 9: link the test executable against EmbeddedCore::Core
    add_test(NAME EmbeddedCoreContract COMMAND embeddedcore_contract_test)
endif()
