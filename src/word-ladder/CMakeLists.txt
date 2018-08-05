cmake_minimum_required(VERSION 3.10)
project(word-ladder CXX)

# cmdline executable
add_executable(word_ladder main.cpp)
target_compile_features(word_ladder PRIVATE cxx_std_14)
target_include_directories(word_ladder PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(word_ladder input_helper)

# test case for GTest
add_executable(test_word_ladder test.cpp)
target_compile_features(test_word_ladder PRIVATE cxx_std_14)
target_include_directories(test_word_ladder PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_word_ladder gtest gtest_main)
