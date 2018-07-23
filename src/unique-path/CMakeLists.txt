cmake_minimum_required(VERSION 3.10)
project(unique-path CXX)

# cmdline executable
add_executable(unique_path main.cpp)
target_compile_features(unique_path PRIVATE cxx_std_14)
target_include_directories(unique_path PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(unique_path input_helper)

# test case for GTest
add_executable(test_unique_path test.cpp)
target_compile_features(test_unique_path PRIVATE cxx_std_14)
target_include_directories(test_unique_path PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_unique_path gtest gtest_main)
