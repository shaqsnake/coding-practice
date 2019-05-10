cmake_minimum_required(VERSION 3.5)
project(sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BubbleSort.h SortUtils.h SelectionSort.h InsertionSort.h ShellSort.h MergeSort.h)
add_executable(sort ${SOURCE_FILES})