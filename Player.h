//
// Created by Alan Ruiz Silva on 22/05/25.
//

#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <string>
using namespace std;

class Player {
private:
    string nombre;
    int posicion;

public:
    Player(string, int);
    void setPosicion(int);
    int getPosicion();
    string getNombre();

};



#endif //PLAYER_H
