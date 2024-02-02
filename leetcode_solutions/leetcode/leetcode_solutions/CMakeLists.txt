set(target_name leetcode_solutions)
aux_source_directory(. source_files)

enable_testing()
add_executable(${target_name} ${source_files})
find_package(GTest CONFIG REQUIRED)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${target_name} PRIVATE leetcode GTest::gtest GTest::gtest_main)
add_test(NAME ${target_name} COMMAND ${target_name})