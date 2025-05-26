//
// Created by Alan Ruiz Silva on 22/05/25.
//

#include "Tablero.h"
#include "CasillaEscalera.h"
#include "CasillaNormal.h"
#include "CasillaSerpiente.h"


Tablero::Tablero() {
    for (int i = 1; i <= 30; i++) {
      casillas[i-1] = new CasillaNormal(i); // Inicializa todas las casillas como normales
      if (i % 3 == 0) {
          casillas[i-1] = new CasillaEscalera(i); // Casilla de escalera cada 3 casillas
      } else if (i % 5 == 0) {
          casillas[i-1] = new CasillaSerpiente(i); // Casilla de serpiente cada 5 casillas
      }
    }
}


Casilla *Tablero::getCasilla(int index) {
    return casillas[index];
}
