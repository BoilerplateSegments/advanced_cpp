
configure_file(nice.csv nice.csv COPYONLY)

add_executable(sample sample.cpp)
target_link_libraries (sample LINK_PUBLIC rapid_csv)

