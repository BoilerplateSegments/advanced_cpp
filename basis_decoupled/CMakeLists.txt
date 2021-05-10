cmake_minimum_required(VERSION 3.17)
project(advanced_cpp_basis)

add_definitions("-Wall" "-g")

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES *.cpp)

FOREACH(SRC ${SRC_FILES})
    get_filename_component(ONLY_NAME_SRC ${SRC} NAME_WE)  # CMAKE 3.14 feature
    add_executable(${ONLY_NAME_SRC} ${SRC})
ENDFOREACH()
