/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
MyGame.h
*****************************************************/

#ifndef MyGame_h
#define MyGame_h

#include "Board.h"
#include "Player.h"
#include "Dice.h"

// Clase que contiene todos los atributos y metodos
// necesarios para representar el juego
class MyGame {
	private:
	    Board	board;			// Tablero
	    Player	player1;		// Jugador 1
	    Player	player2;		// Jugador 2
	    int		turn;			// Turno
	    int		MAX_TURN = 30;	// Numero maximo de turnos
	    Dice	dice;			// Dado
      	int Penalty = 3;
      	int Reward = 3;
      	char Game_Type = 'M';
    
	public:
		MyGame();
    MyGame(int tiles, int snakes,int ladders, int penalty, int reward,int players, char Game_Mode);
		void start(); // Iniciamos el juego
};

#endif /* MyGame_h */
