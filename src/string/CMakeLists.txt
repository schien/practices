cmake_minimum_required(VERSION 3.10)
project(string CXX)

# cmdline executable
add_executable(string main.cpp)
target_compile_features(string PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_string test.cpp)
target_compile_features(test_string PRIVATE cxx_std_14)
target_include_directories(test_string PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_string gtest gtest_main)
