//
// Created by Alan Ruiz Silva on 25/05/25.
//

#include "CasillaNormal.h"


CasillaNormal::CasillaNormal() { } // Constructor por defecto

CasillaNormal::CasillaNormal(int num) : Casilla(num) {} // Constructor que recibe un número

int CasillaNormal::getSiguienteCasilla() {
    return getNumero();
}

char CasillaNormal::getTipo() {
    return 'N';
}
