#ifndef Ladders_h
#define Ladders_h

#include "Tiles.h"
#include <iostream>

class Ladders: public Tiles{
  private:
    char identifier = 'L';
    int reward;

  public:
    Ladders();
    Ladders(int _reward);
    char getIdentifier();
    int getReward();
    
};




#endif /* Ladders_h */