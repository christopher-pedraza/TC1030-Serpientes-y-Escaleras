#ifndef Ladders_h
#define Ladders_h

#include <iostream>

class Ladders {
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