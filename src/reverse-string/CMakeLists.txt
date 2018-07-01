cmake_minimum_required(VERSION 3.10)
project(reverse-string CXX)

# cmdline executable
add_executable(reverse_string main.cpp)
target_compile_features(reverse_string PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_reverse_string test.cpp)
target_compile_features(test_reverse_string PRIVATE cxx_std_14)
target_include_directories(test_reverse_string PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_reverse_string gtest gtest_main)
