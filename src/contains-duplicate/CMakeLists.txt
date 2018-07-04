cmake_minimum_required(VERSION 3.10)
project(contains-duplicate CXX)

# cmdline executable
add_executable(contains_duplicate main.cpp)
target_compile_features(contains_duplicate PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_contains_duplicate test.cpp)
target_compile_features(test_contains_duplicate PRIVATE cxx_std_14)
target_include_directories(test_contains_duplicate PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_contains_duplicate gtest gtest_main)
