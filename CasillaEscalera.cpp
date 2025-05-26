//
// Created by Alan Ruiz Silva on 25/05/25.
//

#include "CasillaEscalera.h"

CasillaEscalera::CasillaEscalera(int num) : Casilla(num) {}

int CasillaEscalera::getSiguienteCasilla() {
    return getNumero() + 3; // Sabiendo que la escalera lleva al número siguiente más 3
}

char CasillaEscalera::getTipo() {
    return 'L';
}
