cmake_minimum_required(VERSION 3.15)
project(some_new_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(some_new_project Test_main.cpp ../project/src/Board.cpp ../project/src/Player.cpp ../project/src/Interface.cpp ../project/include/Board.h ../project/include/Interface.h ../project/include/Player.h ../project/include/ShipPlacement.h Test_Player.h Test_ShipPlacement.h doctest.h Test_Board.h)