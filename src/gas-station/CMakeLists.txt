cmake_minimum_required(VERSION 3.10)
project(gas-station CXX)

# cmdline executable
add_executable(gas_station main.cpp)
target_compile_features(gas_station PRIVATE cxx_std_14)
target_include_directories(gas_station PRIVATE "${inputhelper_SOURCE_DIR}/include")
target_link_libraries(gas_station input_helper)

# test case for GTest
add_executable(test_gas_station test.cpp)
target_compile_features(test_gas_station PRIVATE cxx_std_14)
target_include_directories(test_gas_station PRIVATE "${gtest_SOURCE_DIR}/include")
target_link_libraries(test_gas_station gtest gtest_main)
