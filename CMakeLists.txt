cmake_minimum_required(VERSION 3.24)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)
add_executable(untitled1 main.c validateFile.h SW.h list.h list.c gameboard.c gameboard.h moveValidation.c moveValidation.h card.c)
