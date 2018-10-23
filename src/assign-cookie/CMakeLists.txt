cmake_minimum_required(VERSION 3.10)
project(assign-cookie CXX)

# cmdline executable
add_executable(assign_cookie main.cpp)
target_compile_features(assign_cookie PRIVATE cxx_std_14)
target_include_directories(assign_cookie PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(assign_cookie input_helper)

# test case for GTest
add_executable(test_assign_cookie test.cpp)
target_compile_features(test_assign_cookie PRIVATE cxx_std_14)
target_include_directories(test_assign_cookie PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_assign_cookie gtest gtest_main)
