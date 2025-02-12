cmake_minimum_required(VERSION 3.28.3)
project(assignment1 CXX)


add_executable(num_int_test Num_int_test.cpp)

add_executable(num_int_poly Num_int_poly.cpp)

target_include_directories(num_int_test PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(num_int_poly PUBLIC ${CMAKE_CURRENT_LIST_DIR})

