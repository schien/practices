cmake_minimum_required(VERSION 3.10)
project(bad-version CXX)

# cmdline executable
add_executable(bad_version main.cpp)
target_compile_features(bad_version PRIVATE cxx_std_14)
target_include_directories(bad_version PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(bad_version input_helper)

# test case for GTest
add_executable(test_bad_version test.cpp)
target_compile_features(test_bad_version PRIVATE cxx_std_14)
target_include_directories(test_bad_version PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_bad_version gtest gtest_main)
