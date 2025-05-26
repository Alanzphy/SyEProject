//
// Created by Alan Ruiz Silva on 22/05/25.
//

#ifndef TABLERO_H
#define TABLERO_H

#pragma once
#include "Casilla.h"


class Tablero
{
private:
    Casilla *casillas[30];

public:
    Tablero();
    Casilla *getCasilla(int);


};



#endif //TABLERO_H
