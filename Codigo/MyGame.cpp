/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
MyGame.cpp
*****************************************************/

#include "MyGame.h"
#include "Turn.h"
#include "InvalidConfigurationException.h"


MyGame::MyGame() {
    board 	    = Board(); 		// Tablero
    player1     = Player(1); 	// Jugador 1
    player2     = Player(2); 	// Jugador 2
    turn 	    = 1; 			// Turno
    dice 	    = Dice(); 		// Dado
    MAX_TURN    = 30;	        // Numero maximo de turnos
    Snakes snake;
    Ladders ladder;
    penalty = snake.getPenalty();
    reward = ladder.getReward();
    playerCount = 2;
    players.push_back(Player(1));
    players.push_back(Player(2));
}

MyGame::MyGame(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int _MAX_TURN) {
    board         = Board(_tiles, _snakes, _ladders);
    player1       = Player(1); 	    // Jugador 1
    player2       = Player(2); 	    // Jugador 2
    turn          = 1;
    dice 	      = Dice(); 		// Dado
    MAX_TURN      = _MAX_TURN;
    penalty       = _penalty;
    snake = Snakes(_penalty);
    ladder = Ladders(_reward);
    penalty = snake.getPenalty();
    reward = ladder.getReward();
    playerCount   = _players;
    for (int i = 0; i < playerCount; ++i) {
        players.push_back(Player(i+1));
    }
}

void MyGame::start() { // Iniciamos el juego
    Turn turnObj;

    std::cout << "Tablero generado: " << std::endl;
    board.draw();
    for (int i = 0; i < playerCount; ++i) {
        players[i].setTile(1);
    }
    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl; // Opcion para continuar o no con el juego
    char option = 'C'; // Declaramos la variable tipo caracter para capturar la opcion "C"
    
    bool finished = false;
    int localTurn = 0;

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
            if (option == 'C') { // Opcion "Continuar"
                turnObj.setTurn(turn);
                int number = dice.roll(); 
                turnObj.setPlayerInfo(players[localTurn].draw());
                turnObj.setDiceNumber(number);
                players[localTurn].setTile(players[localTurn].getTile() + number);
                char c = board.getTile(players[localTurn].getTile() - 1);
                turnObj.setBoardTile(c);
                if (c == 'S') { // Si caemos en una serpiente restamos el penalty (penalty)
                    snake.setCasilla(players[localTurn].getTile());
                  
                    players[localTurn].setTile(snake + snake);
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
            else if (option != 'E') { // Si la opcion dada por el usuario es diferente a "E" enviamos un mensaje
                std::cout << "Invalid option, please press C to continue next turn or E to end the game" << std::endl;
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
int MyGame::getPlayerCount() {
    return playerCount;
}
std::vector<Player> MyGame::getPlayers() {
    return players;
}
/*
struct InvalidConfigurationException: public std::exception {
   const char * what () const throw () {
      return "Exception: InvalidConfigurationException";
   }
};
*/