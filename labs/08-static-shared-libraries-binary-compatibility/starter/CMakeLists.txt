cmake_minimum_required(VERSION 3.20)
project(EmbeddedCoreChapter08 VERSION 1.0 LANGUAGES CXX)

include(CTest)

# BUILD_SHARED_LIBS=OFF makes add_library() without a type create a static target.
option(BUILD_SHARED_LIBS "Build EmbeddedCore as a shared library" OFF)

# Internal dependency: do not expose this header directory to app consumers.
add_library(embeddedcore_support STATIC
    support/src/status_format.cpp
)
target_compile_features(embeddedcore_support PUBLIC cxx_std_17)
target_include_directories(embeddedcore_support PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/support/include"
)
# Needed when the static support archive is linked into a Linux shared object.
set_target_properties(embeddedcore_support PROPERTIES POSITION_INDEPENDENT_CODE ON)

# No STATIC/SHARED type: BUILD_SHARED_LIBS controls it at configure time.
add_library(embeddedcore src/sensor.cpp)
add_library(EmbeddedCore::Core ALIAS embeddedcore)
target_compile_features(embeddedcore PUBLIC cxx_std_17)
target_include_directories(embeddedcore
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/support/include"
)
# The internal support library is an implementation dependency.
target_link_libraries(embeddedcore PRIVATE embeddedcore_support)

if(BUILD_SHARED_LIBS)
    # DLL import/export annotations; public because consumers see the header.
    target_compile_definitions(embeddedcore PUBLIC EMBEDDEDCORE_SHARED)
    target_compile_definitions(embeddedcore PRIVATE EMBEDDEDCORE_BUILDING_LIBRARY)
endif()

# Hide symbols by default on compilers that support it; public API is marked.
set_target_properties(embeddedcore PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    OUTPUT_NAME embeddedcore
    VERSION "${PROJECT_VERSION}"
    SOVERSION 1
)

add_executable(DeviceSimulator app/main.cpp)
target_link_libraries(DeviceSimulator PRIVATE EmbeddedCore::Core)

if(WIN32 AND BUILD_SHARED_LIBS)
    # Windows needs embeddedcore.dll adjacent to DeviceSimulator.exe at runtime.
    add_custom_command(TARGET DeviceSimulator POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                "$<TARGET_FILE:embeddedcore>"
                "$<TARGET_FILE_DIR:DeviceSimulator>"
        VERBATIM
        COMMENT "Deploy the EmbeddedCore DLL next to DeviceSimulator"
    )
endif()

if(BUILD_TESTING)
    add_executable(core_test tests/core_test.cpp)
    target_link_libraries(core_test PRIVATE EmbeddedCore::Core)
    if(WIN32 AND BUILD_SHARED_LIBS)
        add_custom_command(TARGET core_test POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                    "$<TARGET_FILE:embeddedcore>" "$<TARGET_FILE_DIR:core_test>"
            VERBATIM
        )
    endif()
    add_test(NAME EmbeddedCoreContract COMMAND core_test)
    add_test(NAME DeviceSimulatorSmoke COMMAND DeviceSimulator)
    set_tests_properties(DeviceSimulatorSmoke PROPERTIES PASS_REGULAR_EXPRESSION "HEALTHY")
endif()
