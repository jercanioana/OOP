cmake_minimum_required(VERSION 3.13)
project(SDALAb2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDALAb2 main.cpp SortedSet.cpp SortedSet.h Iterator.cpp Iterator.h)