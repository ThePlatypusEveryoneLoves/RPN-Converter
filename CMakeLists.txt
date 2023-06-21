cmake_minimum_required(VERSION 3.11)

project(
  	RPNCalc
	VERSION 1.0
  	LANGUAGES CXX)

file(GLOB SRC_FILES 
	${CMAKE_SOURCE_DIR}/src/*.cpp
	${CMAKE_SOURCE_DIR}/src/*.h
)
add_executable(RPNCalc ${SRC_FILES})
