cmake_minimum_required(VERSION 3.10)
project(walking-robot CXX)

# cmdline executable
add_executable(walking_robot main.cpp)
target_compile_features(walking_robot PRIVATE cxx_std_14)
target_include_directories(walking_robot PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(walking_robot input_helper)

# test case for GTest
add_executable(test_walking_robot test.cpp)
target_compile_features(test_walking_robot PRIVATE cxx_std_14)
target_include_directories(test_walking_robot PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_walking_robot gtest gtest_main)
