//
// Created by Alan Ruiz Silva on 25/05/25.
//

#ifndef CASILLANORMAL_H
#define CASILLANORMAL_H
#include "Casilla.h"
using namespace std;

class CasillaNormal : public Casilla {
public:
    CasillaNormal();
    CasillaNormal(int);
    int getSiguienteCasilla() override; // el tablero le pregunta a la casilla a donde debe poner el "token". el jugador le pregunta al tablero
    char getTipo() override; // con esto el tablero sabe que tipo de casilla es, si es normal, si es una casilla normal, casilla serpiente, casilla escalera



};
#endif //CASILLANORMAL_H
