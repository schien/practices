cmake_minimum_required(VERSION 3.10)
project(math CXX)

# cmdline executable
add_executable(math main.cpp)
target_compile_features(math PRIVATE cxx_std_14)
target_include_directories(math PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(math input_helper)

# test case for GTest
add_executable(test_math test.cpp)
target_compile_features(test_math PRIVATE cxx_std_14)
target_include_directories(test_math PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_math gtest gtest_main)
