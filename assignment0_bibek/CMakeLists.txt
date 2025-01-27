cmake_minimum_required(VERSION 3.28.3)
project (computing_at_scale_assignement0 CXX)

add_library(MM_MV_Product MM_MV_Product.cpp)
target_include_directories(MM_MV_Product PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(main main.cpp)
target_link_libraries(main PUBLIC MM_MV_Product)
