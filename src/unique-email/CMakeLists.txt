cmake_minimum_required(VERSION 3.10)
project(unique-email CXX)

# cmdline executable
add_executable(unique_email main.cpp)
target_compile_features(unique_email PRIVATE cxx_std_14)
target_include_directories(unique_email PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(unique_email input_helper)

# test case for GTest
add_executable(test_unique_email test.cpp)
target_compile_features(test_unique_email PRIVATE cxx_std_14)
target_include_directories(test_unique_email PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_unique_email gtest gtest_main)
