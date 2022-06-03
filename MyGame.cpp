/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
MyGame.cpp
*****************************************************/

#include "Dice.h"
#include "Board.h"
#include "MyGame.h"

MyGame::MyGame() {
    board 	= Board(); 		// Tablero
    player1 = Player(1); 	// Jugador 1
    player2 = Player(2); 	// Jugador 2
    turn 	= 1; 			// Turno
    dice 	= Dice(); 		// Dado
}

void MyGame::start() { // Iniciamos el juego
	player1.setTile(1); // Establece la casilla para el jugador 1
    player2.setTile(1); // Establece la casilla para el jugador 2
    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl; // Opcion para continuar o no con el juego
    char option = 'C'; // Declaramos la variable tipo caracter para capturar la opcion "C"
    
	// Comparamos la respuesta dada por el usuario, mientras sea diferente
	// a "E" y el turno no haya pasado el maximo y el jugador 1 y el jugador 2
	// se encuentren dentro del tablero
	while(option != 'E' && turn <= MAX_TURN && player1.getTile() < 30 && player2.getTile() < 30) {
        std::cin >> option; // Capturamos la opcion del usuario
        if (option == 'C') { // Opcion "Continuar"
            std::cout << std::to_string(turn) << " ";
            int number = dice.roll(); 
            if (turn % 2 != 0) {
                // Turno del jugador 1
                std::cout << player1.draw() << " " << number << " ";
                player1.setTile(player1.getTile() + number);
                char c = board.getTile(player1.getTile() - 1);
                std::cout << c << " ";
                if (c == 'S') { // Si caemos en una serpiente restamos el penalty (penalty)
                    player1.setTile(player1.getTile() - 3);
				} else if (c == 'L') { // Si caemos en una escalera sumamos 3 (reward) 
                    player1.setTile(player1.getTile() + 3);
				}
                std::cout << player1.getTile() << std::endl;
            }
            else {
                // Turno del jugador 2
                std::cout << player2.draw() << " " << number << " "; 
                player2.setTile(player2.getTile() + number);
                char c = board.getTile(player2.getTile() - 1);
                std::cout << c << " ";
                if (c == 'S') { // Si caemos en una serpiente restamos 3 (penalty)
                    player2.setTile(player2.getTile() - 3);
				} else if (c == 'L') { // Si caemos en una escalera sumamos 3 (reward)
                    player2.setTile(player2.getTile() + 3);
				}
				std::cout << player2.getTile() << std::endl;
            }
            turn++; // Avanzamos en turno, sumando en 1
        }
        else if (option != 'E') { // Si la opcion dada por el usuario es diferente a "E" enviamos un mensaje
            std::cout << "Invalid option, please press C to continue next turn or E to end the game" << std::endl;
        }
    }
    std::cout << "-- GAME OVER --" << std::endl; // Si ya no hay casillas, terminamos el juego
    
    if (turn >= MAX_TURN) { // Si se ha superado el numero de turnos, enviamos un mensaje indicando lo sucedido al usuario
        std::cout << "The maximum number of turns has been reached..." << std::endl;
	} else if (player1.getTile() >= 30) { // Si el jugador 1 ha recorrido todo el tablero, es decir, llega a la casilla 30, enviamos un mensaje de que el es el ganador
        std::cout << "Player 1 is the winner!!!" << std::endl;
	} else if (player2.getTile() >= 30) { // Si el jugador 2 ha recorrido todo el tablero, es decir, llega a la casilla 30, enviamos un mensaje de que el es el ganador
        std::cout << "Player 2 is the winner!!!" << std::endl;
	} else {// En caso contratrio, enviamos mensaje
        std::cout << "Thanks for playing!!!" << std::endl;
	}
}

