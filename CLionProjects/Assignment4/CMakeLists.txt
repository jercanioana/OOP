cmake_minimum_required(VERSION 3.13)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4 main.c Entities.c Entities.h Repository.c Repository.h Service.c Service.h UI.c UI.h)