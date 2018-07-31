cmake_minimum_required(VERSION 3.10)
project(poker-hands CXX)

# cmdline executable
add_executable(poker_hands main.cpp)
target_compile_features(poker_hands PRIVATE cxx_std_14)
target_include_directories(poker_hands PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(poker_hands input_helper)

# test case for GTest
add_executable(test_poker_hands test.cpp)
target_compile_features(test_poker_hands PRIVATE cxx_std_14)
target_include_directories(test_poker_hands PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_poker_hands gtest gtest_main)
