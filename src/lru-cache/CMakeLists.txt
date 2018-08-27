cmake_minimum_required(VERSION 3.10)
project(lru-cache CXX)

# cmdline executable
add_executable(lru_cache main.cpp)
target_compile_features(lru_cache PRIVATE cxx_std_14)
target_include_directories(lru_cache PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(lru_cache input_helper)

# test case for GTest
add_executable(test_lru_cache test.cpp)
target_compile_features(test_lru_cache PRIVATE cxx_std_14)
target_include_directories(test_lru_cache PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_lru_cache gtest gtest_main)
