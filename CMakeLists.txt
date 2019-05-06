cmake_minimum_required(VERSION 3.8)
project(DisjointSets)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp node.h)
add_executable(DisjointSets ${SOURCE_FILES})