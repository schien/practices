cmake_minimum_required(VERSION 3.10)
project(jolly-jumpers CXX)

# cmdline executable
add_executable(jolly_jumpers main.cpp)
target_compile_features(jolly_jumpers PRIVATE cxx_std_14)
target_include_directories(jolly_jumpers PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(jolly_jumpers input_helper)

# test case for GTest
add_executable(test_jolly_jumpers test.cpp)
target_compile_features(test_jolly_jumpers PRIVATE cxx_std_14)
target_include_directories(test_jolly_jumpers PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_jolly_jumpers gtest gtest_main)
