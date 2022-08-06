cmake_minimum_required(VERSION 3.21)
project(musicELo)

set(CMAKE_CXX_STANDARD 14)

add_executable(musicELo main.cpp
        song.cpp song.h
        vectorStringFunctions.cpp vectorStringFunctions.h songElo.cpp songElo.h inputValidation.cpp inputValidation.h)
