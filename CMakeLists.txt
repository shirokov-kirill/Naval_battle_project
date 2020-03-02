cmake_minimum_required(VERSION 3.10.2)
project(NavalBattle)

include_directories("include/")
include_directories("src/")

set(CMAKE_CXX_STANDARD 11)

add_executable(NavalBattle 
		include/Controller.h  
		include/Player.h 
		include/Interface.h
		include/Board.h
		src/Controller.cpp 
		src/Player.cpp
		src/Interface.cpp
		src/Board.cpp
		src/main.cpp)
