cmake_minimum_required(VERSION 3.17)
project(advanced_cpp)

set(CMAKE_CXX_STANDARD 20)

# Google test
enable_testing()
add_subdirectory(lib/googletest)
add_subdirectory(test)
#

add_subdirectory(lambda)
add_subdirectory(basis)

add_executable(playground playground.cpp)
add_executable(if If.cpp)
