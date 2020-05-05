cmake_minimum_required(VERSION 3.13)
project(Assignment5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment5 main.cpp DynamicVector.h Chore.cpp Chore.h Repository.cpp Repository.h Service.cpp Service.h UI.cpp UI.h main.cpp FileManager.cpp FileManager.h Validator.cpp Validator.h Tests.cpp Tests.h FakeRepository.cpp FakeRepository.h)
