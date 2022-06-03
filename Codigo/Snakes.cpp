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