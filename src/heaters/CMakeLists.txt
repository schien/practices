cmake_minimum_required(VERSION 3.10)
project(heaters CXX)

# cmdline executable
add_executable(heaters main.cpp)
target_compile_features(heaters PRIVATE cxx_std_14)
target_include_directories(heaters PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(heaters input_helper)

# test case for GTest
add_executable(test_heaters test.cpp)
target_compile_features(test_heaters PRIVATE cxx_std_14)
target_include_directories(test_heaters PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_heaters gtest gtest_main)
