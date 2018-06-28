cmake_minimum_required(VERSION 3.10)
project(fizzbuzz CXX)
add_executable(fizzbuzz fizzbuzz.cpp)
set_target_properties(fizzbuzz
  PROPERTIES
  CXX_STANDARD 11
)
