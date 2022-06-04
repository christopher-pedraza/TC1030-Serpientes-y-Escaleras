#include "Automatic.h"

Automatic::Automatic(): MyGame() {
    board 	    = Board(); 		// Tablero
    int numberPlayers = 2;
    Player players[2];
    turn 	    = 1; 			// Turno
    dice 	    = Dice(); 		// Dado
    MAX_TURN    = 30;	        // Numero maximo de turnos
    penalty     = 3;
    reward      = 3;

    for (int i = 0; i < numberPlayers;i++){
            players[i].setNumber(i + 1);
        }
}

Automatic::Automatic(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN): MyGame(_tiles, _snakes, _ladders, _penalty, _reward, _players, MAX_TURN) {
    board         = Board(_tiles, _snakes, _ladders);
    int numberPlayers = _players;
    Player players[_players];
    turn          = 1;
    dice 	      = Dice(); 		// Dado
    MAX_TURN      = MAX_TURN;
    penalty       = _penalty;
    reward        = _reward;
    for (int i = 0; i < numberPlayers;i++){
            players[i].setNumber(i + 1);
        }
}

void Automatic::start() { // Iniciamos el juego

    std::cout << "Tablero generado: " << std::endl;
    board.draw();
	for (int i = 0; i < numberPlayers;i++){
            players[i].setTile(1);
        }
    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl; // Opcion para continuar o no con el juego
    char option = 'C'; // Declaramos la variable tipo caracter para capturar la opcion "C"
    
	// Comparamos la respuesta dada por el usuario, mientras sea diferente
	// a "E" y el turno no haya pasado el maximo y el jugador 1 y el jugador 2
	// se encuentren dentro del tablero
	while(option != 'E' && turn <= MAX_TURN) {
        
        std::cin >> option; // Capturamos la opcion del usuario
        if (option == 'C') { // Opcion "Continuar"
            std::cout << std::to_string(turn) << " ";
            int number = dice.roll(); 

            for (int i = 0; i < numberPlayers;i++){

                std::cout << players[i].draw() << " " << number << " ";
                players[i].setTile(players[i].getTile() + number);
                char c = board.getTile(players[i].getTile() - 1);
                std::cout << c << " ";
                if (c == 'S') { // Si caemos en una serpiente restamos el penalty (penalty)
                    players[i].setTile(players[i].getTile() - penalty);
                } else if (c == 'L') { // Si caemos en una escalera sumamos 3 (reward) 
                    players[i].setTile(players[i].getTile() + reward);
                }
                std::cout << players[i].getTile() << std::endl;
                turn++; // Avanzamos en turno, sumando en 1

    }
    std::cout << "-- GAME OVER --" << std::endl; // Si ya no hay casillas, terminamos el juego
    
    for (int i = 0; i < numberPlayers ;i++){
            if (players[i].getTile() >= 30){
                std::cout << "Player "<<i +1 <<" is the winner!!!" << std::endl;
            }
        }

    if (turn >= MAX_TURN) { // Si se ha superado el numero de turnos, enviamos un mensaje indicando lo sucedido al usuario
        std::cout << "The maximum number of turns has been reached..." << std::endl;
	} else {// En caso contratrio, enviamos mensaje
        std::cout << "Thanks for playing!!!" << std::endl;
	}
        }
    }