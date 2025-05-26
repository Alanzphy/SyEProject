//
// Created by Alan Ruiz Silva on 22/05/25.
//

#include "Casilla.h"
using namespace std;

Casilla::Casilla() {
    myNumber = 0;
}

Casilla::Casilla(int num) {
    myNumber = num;
}

Casilla::~Casilla() {}

int Casilla::getSiguienteCasilla() {
    return myNumber;
}

int Casilla::getNumeroActual() {
    return myNumber;
}

char Casilla::getTipo() {
    return 'N'; // si no se coloca un tipo tomamos como casilla normal
}
