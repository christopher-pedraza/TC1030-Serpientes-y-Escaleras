#include "Ladders.h"

Ladders::Ladders(){
  reward = 3;
  
}
Ladders::Ladders(int _reward){
  reward = _reward;
}


char Ladders::getIdentifier(){
  return identifier;
}

int Ladders::getReward(){
  return reward;
}