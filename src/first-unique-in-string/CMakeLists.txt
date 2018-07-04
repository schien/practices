cmake_minimum_required(VERSION 3.10)
project(first-unique-in-string CXX)

# cmdline executable
add_executable(first-unique-in-string main.cpp)
target_compile_features(first-unique-in-string PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_first_unique_in_string test.cpp)
target_compile_features(test_first_unique_in_string PRIVATE cxx_std_14)
target_include_directories(test_first_unique_in_string PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_first_unique_in_string gtest gtest_main)
