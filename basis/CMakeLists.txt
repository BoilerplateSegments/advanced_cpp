
add_executable(1 01_composing_maps.cpp)
add_executable(2 02_lambda_basis.cpp)
add_executable(3 03_filesystem_basis.cpp)
add_executable(4 04_oop_basis.cpp)
add_executable(5 05_template_basis.cpp)
add_executable(6 06_recrusive_sum_basis.cpp)
add_executable(7 07_no_command_pattern_by_function_ptr.cpp)
add_executable(8 08_closure_struct.cpp)

#google test
add_library(09_googe_test STATIC 09_googe_test.cpp 09_googe_test.h)
target_include_directories(09_googe_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})