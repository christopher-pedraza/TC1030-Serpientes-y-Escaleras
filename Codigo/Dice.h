/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Dice.h
*****************************************************/

#ifndef Dice_h
#define Dice_h

//#include <stdio.h>
#include <cstdlib>
#include <vector>

// Clase Dado
class Dice {
	private:
	    int numberOfOptions; // Veces que se tirara el dado
    
	public:
	    Dice();
	    Dice(int);
	    int roll();
};

#endif /* Dice_h */