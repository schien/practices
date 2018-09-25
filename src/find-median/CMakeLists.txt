cmake_minimum_required(VERSION 3.10)
project(find-median CXX)

# cmdline executable
add_executable(find_median main.cpp)
target_compile_features(find_median PRIVATE cxx_std_14)
target_include_directories(find_median PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(find_median input_helper)

# test case for GTest
add_executable(test_find_median test.cpp)
target_compile_features(test_find_median PRIVATE cxx_std_14)
target_include_directories(test_find_median PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_find_median gtest gtest_main)
