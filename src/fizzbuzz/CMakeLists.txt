cmake_minimum_required(VERSION 3.10)
project(fizzbuzz CXX)

# cmdline executable
add_executable(fizzbuzz main.cpp)
target_compile_features(fizzbuzz PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_fizzbuzz test.cpp)
target_compile_features(test_fizzbuzz PRIVATE cxx_std_14)
target_include_directories(test_fizzbuzz PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_fizzbuzz gtest gtest_main)
