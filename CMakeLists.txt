cmake_minimum_required(VERSION 3.12)
project(labo_04_vecteur)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 11)

add_executable(main.cpp main.cpp Vecteur.h VecteurImpl.h Matrice.h MatriceImpl.h Exception_out_of_range.h Exception_length_error.h Exception_invalid_argument.h Exception_bad_alloc.h overflowManagement.h Exception_overflow_error.h)