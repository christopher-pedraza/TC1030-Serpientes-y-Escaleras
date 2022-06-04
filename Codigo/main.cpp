
/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
main.cpp
*****************************************************/

#include "MyGame.h"
#include "Manual.h"
#include "Automatic.h"

// Con este codigo se inicia el juego
int main(int argc, const char * argv[]) {
    Board table = Board();
    table.draw();

    char option = 'X';
    do {
        std::cout <<  "Customize game (C) or use default values (D)?" << std::endl;
        std::cin >> option;
        if (option == 'C' || option == 'D') {
            if (option == 'D') {
                Manual g; // se crea una nueva instancia del juego para poder llamarlo
                g.start(); // inicia la ejecucion del juego
            } else if (option == 'C') {
                /*
                Agregar condiciones para preguntar los parámetros del juego
                */
            }
            break;
        }
    } while(true);
    


    return 0;
}
