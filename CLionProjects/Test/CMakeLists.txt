cmake_minimum_required(VERSION 3.13)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test main.cpp DynamicVector.h Repository.cpp Repository.h Service.cpp Service.h Console.cpp Console.h PowerWord.cpp PowerWord.h)