/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Dice.cpp
*****************************************************/

#include "Dice.h"

// El dado
Dice::Dice() {
    numberOfOptions = 6; // numero de caras del dado
}

Dice::Dice(int n) {
    numberOfOptions = n; // veces que se tirara el dado
}

int Dice::roll() { // simulamos el tiro del dado de manera aleatoria
    return 1 + (rand() % numberOfOptions);
}