cmake_minimum_required(VERSION 3.10)
project(minesweeper CXX)

# cmdline executable
add_executable(minesweeper main.cpp)
target_compile_features(minesweeper PRIVATE cxx_std_14)
target_include_directories(minesweeper PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(minesweeper input_helper)

# test case for GTest
add_executable(test_minesweeper test.cpp)
target_compile_features(test_minesweeper PRIVATE cxx_std_14)
target_include_directories(test_minesweeper PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_minesweeper gtest gtest_main)
