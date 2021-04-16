add_executable(09_test main.cpp 09_test.cpp)
add_test(NAME 09_test COMMAND 09_test)
target_link_libraries(09_test PUBLIC 09_googe_test gtest)