cmake_minimum_required(VERSION 3.10)
project(trie CXX)

# cmdline executable
add_executable(trie main.cpp)
target_compile_features(trie PRIVATE cxx_std_14)
target_include_directories(trie PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(trie input_helper)

# test case for GTest
add_executable(test_trie test.cpp)
target_compile_features(test_trie PRIVATE cxx_std_14)
target_include_directories(test_trie PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_trie gtest gtest_main)
