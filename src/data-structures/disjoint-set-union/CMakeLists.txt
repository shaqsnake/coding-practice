cmake_minimum_required(VERSION 3.5)
project(Disjoint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. SOURCE_FILES)
add_executable(disjoint.out ${SOURCE_FILES})