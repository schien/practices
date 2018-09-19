cmake_minimum_required(VERSION 3.10)
project(interval CXX)

# cmdline executable
add_executable(interval main.cpp)
target_compile_features(interval PRIVATE cxx_std_14)
target_include_directories(interval PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(interval input_helper)

# test case for GTest
add_executable(test_interval test.cpp)
target_compile_features(test_interval PRIVATE cxx_std_14)
target_include_directories(test_interval PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_interval gtest gtest_main)
