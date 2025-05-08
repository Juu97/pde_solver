cmake_minimum_required(VERSION 3.10)
project(pde_solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/*.hpp)

file(GLOB_RECURSE SOURCES src/*.cpp)

set(SOURCES ${SOURCES} main.cpp)

add_executable(pde_solver ${SOURCES})
