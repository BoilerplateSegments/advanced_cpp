cmake_minimum_required(VERSION 3.17)
project(advanced_cpp)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lambda)
add_subdirectory(filesystem)
add_subdirectory(templates)
add_subdirectory(data_structures)

add_executable(playground playground.cpp)
