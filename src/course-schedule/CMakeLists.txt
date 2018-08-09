cmake_minimum_required(VERSION 3.10)
project(course-schedule CXX)

# cmdline executable
add_executable(course_schedule main.cpp)
target_compile_features(course_schedule PRIVATE cxx_std_14)
target_include_directories(course_schedule PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(course_schedule input_helper)

# test case for GTest
add_executable(test_course_schedule test.cpp)
target_compile_features(test_course_schedule PRIVATE cxx_std_14)
target_include_directories(test_course_schedule PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_course_schedule gtest gtest_main)
