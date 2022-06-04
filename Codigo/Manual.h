#ifndef Manual_h
#define Manual_h

#include <iostream>
#include "MyGame.h"

class Manual: public MyGame {
    protected:
        Board	board;			// Tablero
		int numberPlayers;
	    Player	players[2];
	    int		turn;			// Turno
	    int		MAX_TURN = 30;	// Numero maximo de turnos
	    Dice	dice;			// Dado
      	int		penalty = 3;
      	int		reward = 3;
		//Player	players[]; 
    public:
        void start();
        Manual();
        Manual(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN);
};

#endif /* Manual_h */