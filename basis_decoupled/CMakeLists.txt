cmake_minimum_required(VERSION 3.17)
project(advanced_cpp_basis)

# [Setup env]
set(CMAKE_CXX_STANDARD 20)
add_definitions("-Wall" "-g")
enable_testing()

execute_process(COMMAND "./fetch-doctest.bash"
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        RESULT_VARIABLE fetch_result
        OUTPUT_VARIABLE fetch_output)

#TODO: hide the message is successfully fetched the file
MESSAGE(STATUS "FETCH_RESULT:" ${fetch_result})
MESSAGE(STATUS "OUTPUT_OUTPUTE:" ${fetch_output})

# [Compile def]
file(GLOB SRC_FILES *.cpp)

# TODO: better naming those things
foreach(SRC ${SRC_FILES})

    get_filename_component(BARE_NAME ${SRC} NAME_WE)  # CMAKE 3.14 feature

    if(EXISTS "${PROJECT_SOURCE_DIR}/${BARE_NAME}_test.cpp")
        # message("${PROJECT_SOURCE_DIR}/${BARE_NAME}_test.cpp")

        if(EXISTS "${PROJECT_SOURCE_DIR}/${BARE_NAME}.h")
            set(SRC_LIST "${BARE_NAME}_test.cpp"
                         "${BARE_NAME}.cpp"
                         "${BARE_NAME}.h"
                           doctest.h)
        else()
            set(SRC_LIST "${BARE_NAME}_test.cpp"
                          doctest.h)
        endif()
        # message(${SRC_LIST})
        add_executable(${BARE_NAME} ${SRC_LIST})
        #add_test(NAME ${BARE_NAME} COMMAND ${BARE_NAME})
    else()
        add_executable(${BARE_NAME} ${SRC})
    endif()
    
endforeach()
