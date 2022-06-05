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
	protected:
	    Board	board;			// Tablero
	    Player	player1;		// Jugador 1
	    Player	player2;		// Jugador 2
	    int		turn;			// Turno
	    int		MAX_TURN;		// Numero maximo de turnos
	    Dice	dice;			// Dado
      	int		penalty;
      	int		reward;
		int		playerCount;
		std::vector<Player> players;
    
	public:
		MyGame();
    	MyGame(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN);
		Player getPlayer1();
		Player getPlayer2();
		Board getBoard();
		int getTurn();
		int getMAXTURN();
		Dice getDice();
		int getPenalty();
		int getReward();
		int getPlayerCount();
		std::vector<Player> getPlayers();
		void setPlayer1(Player _player);
		void setPlayer2(Player _player);
		void setBoard(Board _board);
		void setTurn(int _turn);
		void setMAXTURN(int _MAX_TURN);
		void setDice(Dice _dice);
		void setPenalty(int _penalty);
		void setReward(int _reward);
		virtual void start(); // Iniciamos el juego
};

#endif /* MyGame_h */
