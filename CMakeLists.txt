cmake_minimum_required(VERSION 3.9)
project(Parrot)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
	Board.cpp
	Board.h
	Figures.cpp
	Game.cpp
	GameObject.cpp
	File.cpp
	Header.h)

set(MAIN_FILES
	${SOURCE_FILES}
	main.cpp)

set(TESTING_FILES
	${SOURCE_FILES}
	test/catch.hpp
	test/tests.cpp
	test/BoardTest.cpp)

add_executable(ParrotMain ${MAIN_FILES})
add_executable(ParrotTest ${TESTING_FILES})
