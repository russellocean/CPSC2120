cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(testerMain)
add_executable (review Review/testerMain.cpp Review/Review.cpp)