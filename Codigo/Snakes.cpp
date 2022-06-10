#include "Snakes.h"

Snakes::Snakes(){
  penalty = 3;
}
Snakes::Snakes(int _penalty){
  penalty = _penalty;
}
char Snakes::getIdentifier(){
  return identifier;
}

int Snakes::getPenalty(){
  return penalty;
}

int Snakes::getCasilla(){
  return casilla;
}
void Snakes::setCasilla(int _casilla){
  casilla = _casilla;
}

int Snakes::operator +(Snakes& snake){
  
  return (snake.getCasilla() - snake.getPenalty());
}