#ifndef Snakes_h
#define Snakes_h
#include "Tiles.h"
#include <iostream>

class Snakes: public Tiles {
  private:
    char identifier = 'S';
    int penalty;
    int casilla = 0;


  public:
    Snakes();
    Snakes(int _penalty);
    char getIdentifier();
    int getPenalty();
    int getCasilla();
    void setCasilla(int);
    int operator+( Snakes& );
    
    
    
};




#endif /* Snakes_h */