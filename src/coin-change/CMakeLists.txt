cmake_minimum_required(VERSION 3.10)
project(coin-change CXX)

# cmdline executable
add_executable(coin_change main.cpp)
target_compile_features(coin_change PRIVATE cxx_std_14)
target_include_directories(coin_change PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(coin_change input_helper)

# test case for GTest
add_executable(test_coin_change test.cpp)
target_compile_features(test_coin_change PRIVATE cxx_std_14)
target_include_directories(test_coin_change PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_coin_change gtest gtest_main)
