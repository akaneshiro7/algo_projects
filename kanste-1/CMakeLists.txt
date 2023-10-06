cmake_minimum_required(VERSION 3.21)
project(proj_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj_1
        code.cpp
        code.h
        part1.cpp)
