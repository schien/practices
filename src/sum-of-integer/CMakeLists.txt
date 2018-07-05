cmake_minimum_required(VERSION 3.10)
project(sum-of-integer CXX)

# cmdline executable
add_executable(sum_of_integer main.cpp)
target_compile_features(sum_of_integer PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_sum_of_integer test.cpp)
target_compile_features(test_sum_of_integer PRIVATE cxx_std_14)
target_include_directories(test_sum_of_integer PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_sum_of_integer gtest gtest_main)
