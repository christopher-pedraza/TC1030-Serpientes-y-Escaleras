#ifndef Tiles_h
#define Tiles_h

#include <iostream>

class Tiles {
  private:
    char identifier = 'N';
      
  public:
    Tiles();
    virtual char getIdentifier(); 
};

#endif /* Tiles_h */