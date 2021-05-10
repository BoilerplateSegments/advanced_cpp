#google test
add_library(09_googe_test STATIC 09_googe_test.cpp 09_googe_test.h)
target_include_directories(09_googe_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})