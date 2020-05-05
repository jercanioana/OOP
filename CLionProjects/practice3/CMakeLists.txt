cmake_minimum_required(VERSION 3.14)
project(practice3)

set(CMAKE_CXX_STANDARD 14)

add_executable(practice3 main.cpp HospitalDepartment.cpp HospitalDepartment.h NeonatalUnit.cpp NeonatalUnit.h Surgery.cpp Surgery.h Controller.cpp Controller.h UI.cpp UI.h)