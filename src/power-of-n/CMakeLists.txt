cmake_minimum_required(VERSION 3.10)
project(power-of-n CXX)

# cmdline executable
add_executable(power_of_n main.cpp)
target_compile_features(power_of_n PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_power_of_n test.cpp)
target_compile_features(test_power_of_n PRIVATE cxx_std_14)
target_include_directories(test_power_of_n PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_power_of_n gtest gtest_main)
