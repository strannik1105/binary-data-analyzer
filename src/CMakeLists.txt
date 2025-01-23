cmake_minimum_required(VERSION 3.22)

project(binary_data_analyzer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_subdirectory(analyzer)
add_subdirectory(tests)