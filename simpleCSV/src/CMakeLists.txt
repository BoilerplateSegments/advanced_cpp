add_library(rapid_csv csv.cpp csv.h)

target_include_directories (rapid_csv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
