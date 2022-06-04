/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Player.h
*****************************************************/

#ifndef Player_h
#define Player_h

//#include <stdio.h>
//#include <string>
#include <iostream>

// Clase correspondiente al jugador, en la que encontramos los metodos correspondientes
// al jugador, dibujamos el tablero y vamos obteniendo las casillas

class Player {
	private:
	    int number; // Numero de jugador
	    int tile;   // Casilla
    
	public:
	    Player();
	    Player(int);
	    std::string draw();
	    void setTile(int);
		void setNumber(int _number);
	    int getTile();
};

#endif /* Player_h */