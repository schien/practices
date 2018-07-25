cmake_minimum_required(VERSION 3.10)
project(random-set CXX)

# cmdline executable
add_executable(random_set main.cpp)
target_compile_features(random_set PRIVATE cxx_std_14)
target_include_directories(random_set PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(random_set input_helper)

# test case for GTest
add_executable(test_random_set test.cpp)
target_compile_features(test_random_set PRIVATE cxx_std_14)
target_include_directories(test_random_set PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_random_set gtest gtest_main)
