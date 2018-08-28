cmake_minimum_required(VERSION 3.10)
project(n-ary-tree CXX)

# cmdline executable
add_executable(n_ary_tree main.cpp)
target_compile_features(n_ary_tree PRIVATE cxx_std_14)
target_include_directories(n_ary_tree PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(n_ary_tree input_helper)

# test case for GTest
add_executable(test_n_ary_tree test.cpp)
target_compile_features(test_n_ary_tree PRIVATE cxx_std_14)
target_include_directories(test_n_ary_tree PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_n_ary_tree gtest gtest_main)
