cmake_minimum_required(VERSION 3.13)
project(uSDA1)

set(CMAKE_CXX_STANDARD 14)

add_executable(uSDA1 main.cpp Container.cpp Container.h MatrixIterator.cpp MatrixIterator.h)