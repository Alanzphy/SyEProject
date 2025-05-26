cmake_minimum_required(VERSION 3.31)
project(snakes)

set(CMAKE_CXX_STANDARD 20)

add_executable(snakes snakes.cpp
        Casilla.cpp
        Casilla.h
        Dice.cpp
        Dice.h
        Player.cpp
        Player.h
        Game.cpp
        Game.h
        Tablero.cpp
        Tablero.h
        CasillaSerpiente.cpp
        CasillaSerpiente.h
        CasillaEscalera.cpp
        CasillaEscalera.h
        CasillaNormal.cpp
        CasillaNormal.h
)
