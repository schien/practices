cmake_minimum_required(VERSION 3.10)
project(3n-plus-1 CXX)

# cmdline executable
add_executable(3n_plus_1 main.cpp)
target_compile_features(3n_plus_1 PRIVATE cxx_std_14)
target_include_directories(3n_plus_1 PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(3n_plus_1 input_helper)

# test case for GTest
add_executable(test_3n_plus_1 test.cpp)
target_compile_features(test_3n_plus_1 PRIVATE cxx_std_14)
target_include_directories(test_3n_plus_1 PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_3n_plus_1 gtest gtest_main)
