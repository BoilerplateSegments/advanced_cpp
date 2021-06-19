#google test
add_library(slb_lib STATIC slb_lib.cpp slb_lib.h)
target_include_directories(slb_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})