cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(algorithm CXX)

enable_testing()

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable(leetcode ${SOURCES})

target_link_libraries(leetcode PUBLIC GTest::GTest GTest::Main)

add_test(NAME leetcode COMMAND leetcode)
# include(GoogleTest)
# gtest_discover_tests(leetcode)