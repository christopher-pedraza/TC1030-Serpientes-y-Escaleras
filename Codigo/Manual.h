#ifndef Manual_h
#define Manual_h

#include <iostream>
#include "MyGame.h"
#include "Turn.h"

class Manual: public MyGame {
    public:
        void start();
        Manual();
        Manual(int _tiles, int _snakes, int _ladders, int _penalty, int _reward, int _players, int MAX_TURN);
};

#endif /* Manual_h */