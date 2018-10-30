cmake_minimum_required(VERSION 3.10)
project(employee-importance CXX)

# cmdline executable
add_executable(employee_importance main.cpp)
target_compile_features(employee_importance PRIVATE cxx_std_14)
target_include_directories(employee_importance PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(employee_importance input_helper)

# test case for GTest
add_executable(test_employee_importance test.cpp)
target_compile_features(test_employee_importance PRIVATE cxx_std_14)
target_include_directories(test_employee_importance PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_employee_importance gtest gtest_main)
