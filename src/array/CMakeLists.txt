cmake_minimum_required(VERSION 3.10)
project(array CXX)

# cmdline executable
add_executable(array main.cpp)
target_compile_features(array PRIVATE cxx_std_14)
target_include_directories(array PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(array input_helper)

# test case for GTest
add_executable(test_array test.cpp)
target_compile_features(test_array PRIVATE cxx_std_14)
target_include_directories(test_array PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_array gtest gtest_main)
