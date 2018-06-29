cmake_minimum_required(VERSION 3.10)
project(reverse-string CXX)
add_executable(reverse_string main.cpp)
set_target_properties(reverse_string
  PROPERTIES
  CXX_STANDARD 11
)
