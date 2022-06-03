
/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
main.cpp
*****************************************************/

#include "MyGame.h"

// Con este codigo se inicia el juego
int main(int argc, const char * argv[]) {
    Board table = Board();
    table.draw();
    MyGame g; // se crea una nueva instancia del juego para poder llamarlo
    g.start(); // inicia la ejecucion del juego
    return 0;
}
