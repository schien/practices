cmake_minimum_required(VERSION 3.10)
project(guess-number CXX)

# cmdline executable
add_executable(guess_number main.cpp)
target_compile_features(guess_number PRIVATE cxx_std_14)
target_include_directories(guess_number PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(guess_number input_helper)

# test case for GTest
add_executable(test_guess_number test.cpp)
target_compile_features(test_guess_number PRIVATE cxx_std_14)
target_include_directories(test_guess_number PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_guess_number gtest gtest_main)
