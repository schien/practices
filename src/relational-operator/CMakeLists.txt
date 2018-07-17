cmake_minimum_required(VERSION 3.10)
project(relational-operator CXX)

# cmdline executable
add_executable(relational_operator main.cpp)
target_compile_features(relational_operator PRIVATE cxx_std_14)
target_include_directories(relational_operator PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(relational_operator input_helper)

# test case for GTest
add_executable(test_relational_operator test.cpp)
target_compile_features(test_relational_operator PRIVATE cxx_std_14)
target_include_directories(test_relational_operator PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_relational_operator gtest gtest_main)
