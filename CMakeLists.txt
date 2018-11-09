# cmake_minimum_required(VERSION <specify CMake version here>)
project(SpaceBattle)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpaceBattle controller/main.cpp modele/Battleship.cpp modele/Battleship.h modele/Coordinate.cpp modele/Coordinate.h modele/Grid.cpp modele/Grid.h modele/Player.cpp modele/Player.h)