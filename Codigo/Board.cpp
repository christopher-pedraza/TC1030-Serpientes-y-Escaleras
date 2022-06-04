/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Board.cpp
*****************************************************/

#include "Board.h"


// Tablero
Board::Board() {
	// Las casillas estan en un vector de 30 posiciones, en donde cada posicion representa una casilla del tablero
    tiles = std::vector<char>(30, normal.getIdentifier()); 
    int snakes  = 0; // serpientes
    int ladders = 0; // escaleras
    tileCount = 30;
    
	// Se genera de manera aleatoria las serpientes en las casillas del tablero
	while(snakes < 3) {
        int index = (rand() % 30);
        if (tiles[index] == normal.getIdentifier() ) {
            tiles[index] = snake.getIdentifier();
	            snakes++;
        }
    }
    
	// Generamos de manera aleatoria las escaleras en las casillas del tablero
	while(ladders < 3) {
        int index = (rand() % 30); 
        if (tiles[index] == normal.getIdentifier()) {
            tiles[index] = ladder.getIdentifier();
            ladders++;
        }
    }
}


Board::Board(int _tiles, int _snakes,int _ladders){
	// Las casillas estan en un vector de n posiciones, en donde cada posicion representa una casilla del tablero
    tiles = std::vector<char>(_tiles, normal.getIdentifier()); 
    int snakes  = 0; // serpientes
    int ladders = 0; // escaleras
    tileCount = _tiles;
    
	// Se genera de manera aleatoria las serpientes en las casillas del tablero
	while(snakes < _snakes) {
        int index = (rand() % 30);
        if (tiles[index] == normal.getIdentifier()) {
            tiles[index] = snake.getIdentifier();
	            snakes++;
        }
    }
    
	// Generamos de manera aleatoria las escaleras en las casillas del tablero
	while(ladders < _ladders) {
        int index = (rand() % 30); 
        if (tiles[index] == normal.getIdentifier()) {
            tiles[index] = ladder.getIdentifier();
            ladders++;
        }
    }
}

// Dibujamos el tablero
std::string Board::draw() {
    std::string brd = "";
    for (int i = 0;i < tiles.size();i++ ) {
        brd += tiles[i];
        brd += " ";
        
    }
    std::cout<<brd<<std::endl;
    return brd;
}

// Obtenemos las casillas del tablero
char Board::getTile(int index) {
    return tiles[index];
}

int Board::getTileCount() {
    return tileCount;
}
