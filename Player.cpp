//
// Created by Alan Ruiz Silva on 22/05/25.
//

#include "Player.h"
using namespace std;

Player::Player(string nom, int pos) {
    nombre = nom;
    posicion = pos;
}

void Player::setPosicion(int pos) {
    posicion = pos;
}

int Player::getPosicion() {
    return posicion;
}

std::string Player::getNombre() {
    return nombre;
}
