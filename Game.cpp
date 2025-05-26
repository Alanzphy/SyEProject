//
// Created by Alan Ruiz Silva on 22/05/25.
//

#include "Game.h"
#include "Player.h"
#include "Tablero.h"
#include "Dice.h"
#include <iostream>

void Game::start() {
    //crear el dado
    Dice dado;

    //crear el tablero
    Tablero tablero;

    //crear los jugadores, arreglo de dos jugadores
    Player jugadores[2] = {
        Player("1",1),
        Player("2",1)
    };

    int maximoTurnos = 100;
    int turno = 1;
    int jugadorActual = 0; // 0 para jugador 1, 1 para jugador 2
    char input;
    bool gameOver = false;
    cout << "Serpientes y Escaleras" << endl;
    cout << "Presiona C para el siguiente turno o E para terminar el juego" << endl;

    while (!gameOver) {
        if (turno > maximoTurnos) {
            cout << "Se ha alcanzado el número máximo de turnos, el juego ha terminado." << endl;
            break;
        }
        // ESTO ES LA LOGICA SI QUIERES QUE EL JUEGO SE DETENGA CON UNA ENTRADA DEL USUARIO
        // cin >> input;
        // input = toupper(input); // Convertir a mayúscula para evitar problemas de entrada
        // if (input != 'C' && input != 'E') {
        //     cout << "Entrada no valida, por favor ingresa C para continuar o E para salir" << endl;
        //     continue;
        // }
        // if (input == 'E') {
        //     cout << "Juego terminado" << endl;
        //     break;
        // }

        Player& jugador = jugadores[jugadorActual];
        int posicionActual = jugador.getPosicion();
        int tirada = dado.getRandomNumber();
        int casillaSiguiente = posicionActual + tirada;
        if (casillaSiguiente > 30) {
            casillaSiguiente = 30; // No puede pasar de la casilla 30
        }
        Casilla* casilla = tablero.getCasilla(casillaSiguiente - 1); // -1 para que coincida con el índice del arreglo
        char tipoCasilla = casilla->getTipo();
        int posicionFinal;

        if (tipoCasilla == 'L' || tipoCasilla == 'S') {
            posicionFinal = casilla->getSiguienteCasilla();
            if (posicionFinal > 30) posicionFinal = 30; // No puede pasar de la casilla
            if (posicionFinal < 1) posicionFinal = 1; // No puede caer por debajo de la casilla 1
        } else {
            posicionFinal = casillaSiguiente; // Casilla normal
        }
        jugador.setPosicion(posicionFinal);

        // Imprimimos el turno y la información del jugador
        cout << "Turno: " << turno << ": Jugador " << jugador.getNombre()
        << " tiro un " << tirada
        << " y se mueve a la casilla " << posicionFinal
        << " (" << tipoCasilla << ")" << endl;

    //     cout << turno << " "
    //  << jugador.getNombre() << " "
    //  << posInicial << " "
    //  << tirada << " "
    //  << tipo << " "
    //  << posFinal << "\n";


        // checamos si el jugador gano
        if (posicionFinal == 30) {
            cout << "Jugador " << jugador.getNombre() << " ha ganado!" << endl;
            gameOver = true;
            break;
        }

        // Pasamos al siguiente jugador
        turno++;
        if (jugadorActual == 0) {
            jugadorActual = 1; // Cambiamos al segundo jugador
        } else {
            jugadorActual = 0; // Volvemos al primer jugador
        }
    }

}
