cmake_minimum_required(VERSION 3.20)
project(git_SpikeLisp)

set(CMAKE_CXX_STANDARD 23)

add_executable(spike main.cpp)

add_subdirectory(test)
