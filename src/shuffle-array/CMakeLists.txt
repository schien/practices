cmake_minimum_required(VERSION 3.10)
project(shuffle-array CXX)

# cmdline executable
add_executable(shuffle_array main.cpp)
target_compile_features(shuffle_array PRIVATE cxx_std_14)
target_include_directories(shuffle_array PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(shuffle_array input_helper)

# test case for GTest
add_executable(test_shuffle_array test.cpp)
target_compile_features(test_shuffle_array PRIVATE cxx_std_14)
target_include_directories(test_shuffle_array PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_shuffle_array gtest gtest_main)
