
/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
main.cpp
*****************************************************/

#include "MyGame.h"
#include "Manual.h"
#include "Automatic.h"

// Con este codigo se inicia el juego
int main(int argc, const char * argv[]) {
    char option = 'X';
    do {
        std::cout <<  "Customize game (C) or use default values (D)?" << std::endl;
        std::cin >> option;
        if (option == 'C' || option == 'D') {
            if (option == 'D') {
                Manual g; // se crea una nueva instancia del juego para poder llamarlo
                g.start(); // inicia la ejecucion del juego
            } else if (option == 'C') {
                int tiles, snakes, ladders, penalty, reward, players, maxTurn;
                char modoJuego;

                /*
                std::cout << "Cantidad de casillas: " << std::endl;
                std::cin >> tiles;
                std::cout << "Cantidad de casillas con serpientes: " << std::endl;
                std::cin >> snakes;
                std::cout << "Cantidad de casillas con escaleras" << std::endl;
                std::cin >> ladders;
                std::cout << "Casillas penalizadas al caer en casilla de serpiente: " << std::endl;
                std::cin >> penalty;
                std::cout << "Casillas otorgadas al caer en casilla de escalera: " << std::endl;
                std::cin >> reward;
                std::cout << "Cantidad de jugadores: " << std::endl;
                std::cin >> players;
                std::cout << "Cantidad máxima de turnos: " << std::endl;
                std::cin >> maxTurn;
                std::cout << "Modo automático (A) o manual (M)?" << std::endl;
                std::cin >> modoJuego;
                */

                tiles = 20;
                snakes = 3;
                ladders = 3;
                penalty = 3;
                reward = 3;
                players = 3;
                maxTurn = 40;
                modoJuego = 'A';

                if (modoJuego == 'A') {
                    Automatic juegoAutomatico = Automatic(tiles, snakes, ladders, penalty, reward, players, maxTurn);
                    juegoAutomatico.start();
                } else if (modoJuego == 'M') {
                    Manual juegoManual = Manual(tiles, snakes, ladders, penalty, reward, players, maxTurn);
                    juegoManual.start();
                } else {
                    std::cout << "Modo no identificado. Se usará modo Manual." << std::endl;
                    Manual juegoManual = Manual(tiles, snakes, ladders, penalty, reward, players, maxTurn);
                    juegoManual.start();
                }
            }
            break;
        }
    } while(true);
    


    return 0;
}
