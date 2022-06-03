#ifndef Snakes_h
#define Snakes_h

#include <iostream>

class Snakes {
  private:
    char identifier = 'S';
    int penalty;


  public:
    Snakes();
    Snakes(int _penalty);
    char getIdentifier();
    int getPenalty();
    
    
    
};




#endif /* Snakes_h */