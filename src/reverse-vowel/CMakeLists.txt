cmake_minimum_required(VERSION 3.10)
project(reverse-vowel CXX)

# cmdline executable
add_executable(reverse_vowel main.cpp)
target_compile_features(reverse_vowel PRIVATE cxx_std_14)

# test case for GTest
add_executable(test_reverse_vowel test.cpp)
target_compile_features(test_reverse_vowel PRIVATE cxx_std_14)
target_include_directories(test_reverse_vowel PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_reverse_vowel gtest gtest_main)
