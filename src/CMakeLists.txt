cmake_minimum_required(VERSION 3.15.3)
project(musicEloSrc)

set(CMAKE_CXX_STANDARD 14)

add_library(musicEloSrc
        main.cpp
        song.cpp song.h
        vectorStringFunctions.cpp vectorStringFunctions.h songElo.cpp songElo.h inputValidation.cpp inputValidation.h test.cpp songEloTestable.cpp songEloTestable.h)
target_compile_options(musicEloSrc PRIVATE -Wall -Werror)
target_include_directories(musicEloSrc PUBLIC .)

add_executable(musicElo main.cpp)
target_link_libraries(musicElo PRIVATE musicEloSrc)

target_compile_options(musicElo PRIVATE -Wall -Werror)