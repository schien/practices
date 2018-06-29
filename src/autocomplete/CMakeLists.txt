cmake_minimum_required(VERSION 3.10)
project(autocomplete CXX)
add_executable(autocomplete autocomplete.cpp)
set_target_properties(autocomplete
  PROPERTIES
  CXX_STANDARD 11
)
