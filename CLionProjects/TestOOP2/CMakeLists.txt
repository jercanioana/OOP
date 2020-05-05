cmake_minimum_required(VERSION 3.14)
project(TestOOP2)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestOOP2 main.cpp Dwelling.cpp Dwelling.h Client.cpp Client.h NormalClient.cpp NormalClient.h WealthyClient.cpp WealthyClient.h UI.cpp UI.h RealEstateAgency.cpp RealEstateAgency.h)