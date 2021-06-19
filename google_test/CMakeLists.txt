cmake_minimum_required(VERSION 3.17)
project(advanced_cpp)

set(CMAKE_CXX_STANDARD 20)

# Google test
enable_testing()
add_subdirectory(thirdparty/googletest)

# my library
add_subdirectory(slb_lib)

# testing folder
add_subdirectory(test)
