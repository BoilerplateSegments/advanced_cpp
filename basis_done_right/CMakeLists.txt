cmake_minimum_required(VERSION 3.17)
project(advanced_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(01 01_TMP.cpp)
add_executable(02 02_string_view.cpp)

find_package(fmt)
if(fmt_FOUND)
    add_executable(03 03_fmt.cpp)
    target_link_libraries(03 fmt::fmt)
else()
    message(!fmt not found, 03 disabled)
endif()
