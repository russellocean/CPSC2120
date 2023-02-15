cmake_minimum_required(VERSION 3.23)
project(QueueImplementationUsingACircularArray)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(QueueImplementationUsingACircularArray
        "Circular Array Queue Sample Test Cases/T1.cpp"
        IntegerArrayQueue.cpp
        IntegerArrayQueue.h)
