//
// Created by Alan Ruiz Silva on 25/05/25.
//

#ifndef CASILLAESCALERA_H
#define CASILLAESCALERA_H

#include "Casilla.h"

class CasillaEscalera : public Casilla {
public:
    CasillaEscalera(int);
    int getSiguienteCasilla() override;
    char getTipo() override;
};

#endif // CASILLAESCALERA_H




