cmake_minimum_required(VERSION 3.22)
project(sudoku)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku main.cpp game.cpp game.h)
