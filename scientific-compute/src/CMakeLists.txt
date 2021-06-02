include(FetchContent)

FetchContent_Declare(eign_git
    GIT_REPOSITORY git@gitlab.com:libeigen/eigen.git
    GIT_TAG        3.4-rc1)

FetchContent_MakeAvailable(eign_git)

add_executable(eign)

# Magic!
target_sources(eign PUBLIC matrix_trial.cpp)
target_link_libraries (eign Eigen3::Eigen)

add_executable(gsl_test gsl_test.cpp)
find_package(GSL REQUIRED)
target_link_libraries(gsl_test GSL::gsl GSL::gslcblas)
#                              ^ doc
#  https://cmake.org/cmake/help/latest/module/FindGSL.html
