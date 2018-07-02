cmake_minimum_required(VERSION 3.10)
project(linked-list CXX)

# cmdline executable
add_executable(linked_list main.cpp)
target_compile_features(linked_list PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_linked_list test.cpp)
target_compile_features(test_linked_list PRIVATE cxx_std_14)
target_include_directories(test_linked_list PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_linked_list gtest gtest_main)
