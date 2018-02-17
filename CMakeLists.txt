cmake_minimum_required(VERSION 3.9)
project(Parrot)

set(CMAKE_CXX_STANDARD 11)

add_executable(Parrot
    test/BoardTest.cpp
    test/catch.hpp
    test/tests.cpp
    .gitignore
    Board.cpp
    Board.h
    CMakeLists.txt
    Figures.cpp
    File.cpp
    Game.cpp
    GameObject.cpp
    Header.h
    main.cpp
    README.md
    ToDoList.txt)
