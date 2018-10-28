cmake_minimum_required(VERSION 3.10)
project(baseball-game CXX)

# cmdline executable
add_executable(baseball_game main.cpp)
target_compile_features(baseball_game PRIVATE cxx_std_14)
target_include_directories(baseball_game PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(baseball_game input_helper)

# test case for GTest
add_executable(test_baseball_game test.cpp)
target_compile_features(test_baseball_game PRIVATE cxx_std_14)
target_include_directories(test_baseball_game PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_baseball_game gtest gtest_main)
