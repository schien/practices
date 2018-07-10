cmake_minimum_required(VERSION 3.10)
project(house-robber CXX)

# cmdline executable
add_executable(house_robber main.cpp)
target_compile_features(house_robber PRIVATE cxx_std_14)
target_include_directories(house_robber PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(house_robber input_helper)

# test case for GTest
add_executable(test_house_robber test.cpp)
target_compile_features(test_house_robber PRIVATE cxx_std_14)
target_include_directories(test_house_robber PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_house_robber gtest gtest_main)
