cmake_minimum_required(VERSION 3.10)
project(min-height-trees CXX)

# cmdline executable
add_executable(min_height_trees main.cpp)
target_compile_features(min_height_trees PRIVATE cxx_std_14)
target_include_directories(min_height_trees PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(min_height_trees input_helper)

# test case for GTest
add_executable(test_min_height_trees test.cpp)
target_compile_features(test_min_height_trees PRIVATE cxx_std_14)
target_include_directories(test_min_height_trees PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_min_height_trees gtest gtest_main)
