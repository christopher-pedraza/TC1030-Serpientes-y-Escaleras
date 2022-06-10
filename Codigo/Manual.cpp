#include "Manual.h"
#include "InvalidOptionException.h"

Manual::Manual(): MyGame() {
}
Manual::Manual(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN): MyGame(_tiles, _snakes, _ladders, _penalty, _reward, _players, MAX_TURN) {
}

void Manual::start() { // Iniciamos el juego
    Turn turnObj;
    std::cout << "Tablero generado: " << std::endl;
    board.draw();
    for (int i = 0; i < playerCount; ++i) {
        players[i].setTile(1);
    }
    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl; // Opcion para continuar o no con el juego
    char option = 'X'; // Declaramos la variable tipo caracter para capturar la opcion "C"
    
    bool finished = false;
    int localTurn = 0;
    int attempts = 0;

	// Comparamos la respuesta dada por el usuario, mientras sea diferente
	// a "E" y el turno no haya pasado el maximo y el jugador 1 y el jugador 2
	// se encuentren dentro del tablero
	while(option != 'E' && turn <= MAX_TURN && !finished) {
        for (int i = 0; i < playerCount; ++i) {
            if (players[i].getTile() >= board.getTileCount()) {
                finished = true;
                break;
            }
        }   

        if (!finished) {
            std::cin >> option; // Capturamos la opcion del usuario
            try {
                if (option != 'C' && option != 'E') {
                    throw InvalidOptionException();
                }
                else {
                    attempts = 0;
                }
            } catch(InvalidOptionException& e) {
                    std::cout << e.what() << std::endl;
                    std::cout << e.message(attempts) << std::endl;
                    
                    attempts++;
                    if (attempts > 5) {
                        break;
                    }
            }

            if (option == 'C') { // Opcion "Continuar"
                turnObj.setTurn(turn);
                int number = dice.roll(); 
                turnObj.setPlayerInfo(players[localTurn].draw());
                turnObj.setDiceNumber(number);
                players[localTurn].setTile(players[localTurn].getTile() + number);
                char c = board.getTile(players[localTurn].getTile() - 1);
                turnObj.setBoardTile(c);
                if (c == 'S') { // Si caemos en una serpiente restamos el penalty (penalty)
                    players[localTurn].setTile(players[localTurn].getTile() - penalty);
                } else if (c == 'L') { // Si caemos en una escalera sumamos 3 (reward) 
                    players[localTurn].setTile(players[localTurn].getTile() + reward);
                }
                turnObj.setNewTile(players[localTurn].getTile());

                std::cout << turnObj;

                localTurn++;
                if (localTurn == playerCount) {
                    localTurn = 0;
                }
                turn++; // Avanzamos en turno, sumando en 1
            } 
        } else {
            break;
        }
    }
    std::cout << "-- GAME OVER --" << std::endl; // Si ya no hay casillas, terminamos el juego
    
    if (turn >= MAX_TURN) { // Si se ha superado el numero de turnos, enviamos un mensaje indicando lo sucedido al usuario
        std::cout << "The maximum number of turns has been reached..." << std::endl;
	} else if (finished) { // Si un jugador ha recorrido todo el tablero, es decir, llega a la casilla tileCount, enviamos un mensaje de que el es el ganador
        for (int i = 0; i < playerCount; ++i) {
            if (players[i].getTile() >= board.getTileCount()) {
                std::cout << "Player " << (i+1) << " is the winner!!!" << std::endl;
            }
        }   
	} else {// En caso contratrio, enviamos mensaje
        std::cout << "Thanks for playing!!!" << std::endl;
	}
}