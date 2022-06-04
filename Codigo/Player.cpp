/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Player.cpp
*****************************************************/

#include "Player.h"

// Jugador
Player::Player() {
    number = 1; // Siempre se inicia con el jugador 1
    tile   = 1; // Se inicia el juego en la casilla 1
}

Player::Player(int n) {
    number = n; // Numero de jugador
    tile   = 1; // Siempre se inicia en la casilla 1 
}

std::string Player::draw() { 
    return std::to_string(number) + " " + std::to_string(tile);
}

void Player::setNumber(int _number){
    number = _number;
}

void Player::setTile(int t) { // Obtenemos las casillas
    if (t < 1) {
		tile = 1;
	}

    else if (t > 30) {
		tile = 30;
	}
    else {
		tile = t;
	}
}

int Player::getTile() {
    return tile; // Regresamos la casilla al jugador que corresponde
}