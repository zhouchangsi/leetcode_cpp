set(lib_name leetcode)

include_directories(.)

add_library(${lib_name} leetcode.cpp leetcode.h)
target_include_directories(${lib_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# find all test files end with *_test.cpp
file(GLOB_RECURSE test_files *_test.cpp)

# build test target
find_package(GTest CONFIG REQUIRED)
add_executable(${lib_name}_test ${test_files})
target_link_libraries(${lib_name}_test ${lib_name} GTest::gtest GTest::gtest_main)

# run test post build
if(RUN_TEST)
    add_custom_command(TARGET ${lib_name}_test POST_BUILD COMMAND ${lib_name}_test)
endif()