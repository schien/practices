cmake_minimum_required(VERSION 3.10)
project(graph CXX)

# cmdline executable
add_executable(graph main.cpp)
target_compile_features(graph PRIVATE cxx_std_14)
target_include_directories(graph PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(graph input_helper)

# test case for GTest
add_executable(test_graph test.cpp)
target_compile_features(test_graph PRIVATE cxx_std_14)
target_include_directories(test_graph PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_graph gtest gtest_main)
