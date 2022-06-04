/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Board.h
*****************************************************/

#ifndef Board_h
#define Board_h

//#include <iostream>
//#include <stdio.h>
//#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "Snakes.h"
#include "Ladders.h"
#include "Tiles.h"

// Clase tablero que contiene el vector en que representa las 
// casillas y los metodos correspondientes para generar el tablero
class Board {
  private:
    std::vector<char> tiles;
    Tiles normal;
    Snakes snake;
    Ladders ladder;
    int tileCount;
    
  public:
    Board();
    Board(int tiles, int snakes, int ladders);
    std::string draw();
    char getTile(int);
    int getTileCount();
};

    

#endif /* Board_h */