cmake_minimum_required (VERSION 3.10)
project(practices)

enable_testing()
## Setup for GTest
add_subdirectory(lib/googletest EXCLUDE_FROM_ALL)

add_subdirectory(lib/input_helper EXCLUDE_FROM_ALL)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_subdirectory(src/fizzbuzz)
add_subdirectory(src/autocomplete)
add_subdirectory(src/reverse-string)
add_subdirectory(src/reverse-vowel)
add_subdirectory(src/linked-list)
add_subdirectory(src/contains-duplicate)
add_subdirectory(src/first-unique-in-string)
add_subdirectory(src/power-of-n)
add_subdirectory(src/sum-of-integer)
add_subdirectory(src/number)
add_subdirectory(src/array)
add_subdirectory(src/string)
add_subdirectory(src/house-robber)
add_subdirectory(src/tree)
add_subdirectory(src/3n-plus-1)
