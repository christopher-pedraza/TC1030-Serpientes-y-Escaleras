/****************************************************
TC10MAX_TURN - Equipo 8
SerpientesEscaleras
MyGame.cpp
*****************************************************/

#include "MyGame.h"

MyGame::MyGame() {
    board 	    = Board(); 		// Tablero
    player1     = Player(1); 	// Jugador 1
    player2     = Player(2); 	// Jugador 2
    turn 	    = 1; 			// Turno
    dice 	    = Dice(); 		// Dado
    MAX_TURN    = 30;	        // Numero maximo de turnos
    penalty     = 3;
    reward      = 3;
}

MyGame::MyGame(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN) {
    board         = Board(_tiles, _snakes, _ladders);
    player1       = Player(1); 	    // Jugador 1
    player2       = Player(2); 	    // Jugador 2
    turn          = 1;
    dice 	      = Dice(); 		// Dado
    MAX_TURN      = MAX_TURN;
    penalty       = _penalty;
    reward        = _reward;
}

void MyGame::start() { // Iniciamos el juego
	player1.setTile(1); // Establece la casilla para el jugador 1
    player2.setTile(1); // Establece la casilla para el jugador 2
    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl; // Opcion para continuar o no con el juego
    char option = 'C'; // Declaramos la variable tipo caracter para capturar la opcion "C"
    
	// Comparamos la respuesta dada por el usuario, mientras sea diferente
	// a "E" y el turno no haya pasado el maximo y el jugador 1 y el jugador 2
	// se encuentren dentro del tablero
	while(option != 'E' && turn <= MAX_TURN && player1.getTile() < MAX_TURN && player2.getTile() < MAX_TURN) {
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
                    player1.setTile(player1.getTile() - penalty);
				} else if (c == 'L') { // Si caemos en una escalera sumamos 3 (reward) 
                    player1.setTile(player1.getTile() + reward);
				}
                std::cout << player1.getTile() << std::endl;
            }
            else {
                // Turno del jugador 2
                std::cout << player2.draw() << " " << number << " "; 
                player2.setTile(player2.getTile() + number);
                char c = board.getTile(player2.getTile() - 1);
                std::cout << c << " ";
                if (c == 'S') { // Si caemos en una serpiente restamos (penalty)
                    player2.setTile(player2.getTile() - penalty);
				} else if (c == 'L') { // Si caemos en una escalera sumamos (reward)
                    player2.setTile(player2.getTile() + reward);
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
	} else if (player1.getTile() >= MAX_TURN) { // Si el jugador 1 ha recorrido todo el tablero, es decir, llega a la casilla MAX_TURN, enviamos un mensaje de que el es el ganador
        std::cout << "Player 1 is the winner!!!" << std::endl;
	} else if (player2.getTile() >= MAX_TURN) { // Si el jugador 2 ha recorrido todo el tablero, es decir, llega a la casilla MAX_TURN, enviamos un mensaje de que el es el ganador
        std::cout << "Player 2 is the winner!!!" << std::endl;
	} else {// En caso contratrio, enviamos mensaje
        std::cout << "Thanks for playing!!!" << std::endl;
	}
}

Player MyGame::getPlayer1() {
    return player1;
}
Player MyGame::getPlayer2(){
    return player2;
}
Board MyGame::getBoard(){
    return board;
}
int MyGame::getTurn(){
    return turn;
}
int MyGame::getMAXTURN(){
    return MAX_TURN;
}
Dice MyGame::getDice(){
    return dice;
}
int MyGame::getPenalty(){
    return penalty;
}
int MyGame::getReward(){
    return reward;
}