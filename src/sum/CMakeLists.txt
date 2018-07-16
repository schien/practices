cmake_minimum_required(VERSION 3.10)
project(sum CXX)

# cmdline executable
add_executable(sum main.cpp)
target_compile_features(sum PRIVATE cxx_std_14)
target_include_directories(sum PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(sum input_helper)

# test case for GTest
add_executable(test_sum test.cpp)
target_compile_features(test_sum PRIVATE cxx_std_14)
target_include_directories(test_sum PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_sum gtest gtest_main)
