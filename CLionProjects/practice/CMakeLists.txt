cmake_minimum_required(VERSION 3.13)
project(practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(practice main.cpp Repository.cpp Repository.h Service.cpp Service.h Console.cpp Console.h DynamicVector.h Team.cpp Team.h)