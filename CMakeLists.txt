cmake_minimum_required(VERSION 3.13)
project(labo_04_vecteur)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 11)

add_executable(main.cpp main.cpp)