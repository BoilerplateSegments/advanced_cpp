add_executable(my_test main.cpp test_instance.cpp)
add_test(NAME my_test COMMAND 09_test)
target_link_libraries(my_test PUBLIC slb_lib gtest)