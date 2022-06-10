
/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
main.cpp
*****************************************************/

#include "MyGame.h"
#include "Manual.h"
#include "Automatic.h"
#include "InvalidConfigurationException.h"

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

                std::cout << "Cantidad de casillas: " << std::endl;
                try {
                    std::cin >> tiles;
                    if (tiles < 2) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("tiles", tiles);
                    return 1;
                }

                std::cout << "Cantidad de casillas con serpientes: " << std::endl;
                try {
                    std::cin >> snakes;
                    if (snakes < 1) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("snakes", snakes);
                    return 1;
                }

                std::cout << "Cantidad de casillas con escaleras" << std::endl;
                try {
                    std::cin >> ladders;
                    if (ladders < 1) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("ladders", ladders);
                    return 1;
                }

                std::cout << "Casillas penalizadas al caer en casilla de serpiente: " << std::endl;
                try {
                    std::cin >> penalty;
                    if (penalty < 0) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("penalty", penalty);
                    return 1;
                }

                std::cout << "Casillas otorgadas al caer en casilla de escalera: " << std::endl;
                try {
                    std::cin >> reward;
                    if (reward < 0) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("reward", reward);
                    return 1;
                }

                std::cout << "Cantidad de jugadores: " << std::endl;
                try {
                    std::cin >> players;
                    if (players < 1) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("players", players);
                    return 1;
                }

                std::cout << "Cantidad máxima de turnos: " << std::endl;
                try {
                    std::cin >> maxTurn;
                    if (maxTurn < 1) {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("maxTurn", maxTurn);
                    return 1;
                }

                std::cout << "Modo automático (A) o manual (M)?" << std::endl;
                try {
                    std::cin >> modoJuego;
                    if (modoJuego != 'M' && modoJuego != 'A') {
                        throw InvalidConfigurationException();
                    }
                } catch(InvalidConfigurationException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.config("modoJuego", modoJuego);
                    return 1;
                }

                if (modoJuego == 'A') {
                    Automatic juegoAutomatico = Automatic(tiles, snakes, ladders, penalty, reward, players, maxTurn);
                    juegoAutomatico.start();
                } else if (modoJuego == 'M') {
                    Manual juegoManual = Manual(tiles, snakes, ladders, penalty, reward, players, maxTurn);
                    juegoManual.start();
                }
            }
            break;
        }
    } while(true);

    return 0;
}
