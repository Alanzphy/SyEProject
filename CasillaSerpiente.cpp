//
// Created by Alan Ruiz Silva on 25/05/25.
//
#include "CasillaSerpiente.h"

CasillaSerpiente::CasillaSerpiente(int num) : Casilla(num) {}

int CasillaSerpiente::getSiguienteCasilla() {
    return getNumero() - 3;
}

char CasillaSerpiente::getTipo() {
    return 'S';
}
