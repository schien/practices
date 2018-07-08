cmake_minimum_required (VERSION 3.10)
project(inputhelper)

include_directories(${inputhelper_SOURCE_DIR}/include)

add_library(input_helper "src/input_helper.cpp")
target_compile_features(input_helper PRIVATE cxx_std_14)

target_include_directories(input_helper INTERFACE "${inputhelper_SOURCE_DIR}/include")
