cmake_minimum_required(VERSION 3.10)
project(number CXX)

# cmdline executable
add_executable(number main.cpp)
target_compile_features(number PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_number test.cpp)
target_compile_features(test_number PRIVATE cxx_std_14)
target_include_directories(test_number PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_number gtest gtest_main)
