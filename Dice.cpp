//
// Created by Alan Ruiz Silva on 22/05/25.
//

#include "Dice.h"
using namespace std;
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    srand((int)time(0));
}


int Dice::getRandomNumber() { // el metodo getRandomNumber() es lo mismo que el metodo roll()
    return rand() % 6 + 1;
}
