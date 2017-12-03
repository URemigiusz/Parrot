cmake_minimum_required(VERSION 3.8)
project(Parrot)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Board.cpp
        Board.h
        Figures.cpp
        Game.cpp
        GameObject.cpp
        Header.h
        File.cpp
        main.cpp)

add_executable(Parrot ${SOURCE_FILES})