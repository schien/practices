cmake_minimum_required(VERSION 3.10)
project(tree CXX)

# cmdline executable
add_executable(tree main.cpp)
target_compile_features(tree PRIVATE cxx_std_14)
target_include_directories(tree PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(tree input_helper)

# test case for GTest
add_executable(test_tree test.cpp)
target_compile_features(test_tree PRIVATE cxx_std_14)
target_include_directories(test_tree PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_tree gtest gtest_main)
