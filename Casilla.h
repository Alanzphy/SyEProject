//
// Created by Alan Ruiz Silva on 22/05/25.
//

#ifndef CASILLA_H
#define CASILLA_H
using namespace std;
#pragma once
#include <string>

class Casilla {
private:
    int myNumber;
public:
    Casilla();
    Casilla(int);
    virtual ~Casilla();
    int getNumeroActual(); //el tablero le pregunta la casilla cual es su numero actual, esto quizas para saber si a ganado o no
    virtual int getSiguienteCasilla()  ; //el tablero le pregunta a la casilla a donde debe poner el "token". el jugador le pregunta al tablero
    virtual char getTipo(); // con esto el tablero sabe que tipo de casilla es, si es normal, si es una casilla normal, casilla serpiente, casilla escalera
    int getNumero() {
        return myNumber;
    }
};

#endif //CASILLA_H
