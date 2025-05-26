//
// Created by Alan Ruiz Silva on 25/05/25.
//

#ifndef CASILLASERPIENTE_H
#define CASILLASERPIENTE_H

#include "Casilla.h"

class CasillaSerpiente : public Casilla {
public:
    CasillaSerpiente();
    CasillaSerpiente(int);
    int getSiguienteCasilla() override;
    char getTipo() override;
};

#endif // CASILLASERPIENTE_H

