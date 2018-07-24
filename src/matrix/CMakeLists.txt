cmake_minimum_required(VERSION 3.10)
project(matrix CXX)

# cmdline executable
add_executable(matrix main.cpp)
target_compile_features(matrix PRIVATE cxx_std_14)
target_include_directories(matrix PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(matrix input_helper)

# test case for GTest
add_executable(test_matrix test.cpp)
target_compile_features(test_matrix PRIVATE cxx_std_14)
target_include_directories(test_matrix PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_matrix gtest gtest_main)
