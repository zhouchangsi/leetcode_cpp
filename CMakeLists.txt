cmake_minimum_required(VERSION 3.15)
project(algorithm CXX)

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable(leetcode ${SOURCES})

target_include_directories(leetcode PUBLIC ${GTest_INCLUDE_DIRS})
target_link_libraries(leetcode PUBLIC GTest::GTest GTest::Main)