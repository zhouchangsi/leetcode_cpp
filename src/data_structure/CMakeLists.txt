set(target_name lib_data_structure)

# find all source files without *_test.cpp
aux_source_directory(. source_files)
list(FILTER source_files EXCLUDE REGEX ".*_test.cpp$")

message(STATUS "source_files: ${source_files}")

# build target
add_library(${target_name} ${source_files})
target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# find all test files end with *_test.cpp
file(GLOB_RECURSE test_files *_test.cpp)

# build test target
find_package(GTest CONFIG REQUIRED)
add_executable(${target_name}_test ${test_files})
target_link_libraries(${target_name}_test ${target_name} GTest::gtest GTest::gtest_main)

# run test post build
if(RUN_LIB_DATA_STRUCTURE_TEST)
    add_custom_command(TARGET ${target_name}_test POST_BUILD COMMAND ${target_name}_test)
endif()