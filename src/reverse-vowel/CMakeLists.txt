cmake_minimum_required(VERSION 3.10)
project(reverse-vowel CXX)
add_executable(reverse_vowel main.cpp)
set_target_properties(reverse_vowel
  PROPERTIES
  CXX_STANDARD 11
)
