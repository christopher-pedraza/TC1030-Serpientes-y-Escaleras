#ifndef Automatic_h
#define Automatic_h

#include <iostream>
#include "MyGame.h"
#include "Turn.h"

class Automatic: public MyGame {
    public:
        void start();
        Automatic();
        Automatic(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN);
};

#endif /* Automatic_h */