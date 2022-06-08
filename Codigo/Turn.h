/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Turn.h
*****************************************************/

#ifndef Turn_h
#define Turn_h

#include <iostream>


class Turn {
  protected:
    int turn;
    int diceNumber;
    std::string playerInfo;
    int newTile;
    char boardTile;
 
  public:
    Turn();
    Turn(int _turn, int _diceNumber, std::string _playerInfo, char _newTile, char _boardTile);
    void setTurn(int _turn);
    void setDiceNumber(int _diceNumber);
    void setPlayerInfo(std::string _playerInfo);
    void setNewTile(int _newTile);
    void setBoardTile(char _boardTile);
    friend std::ostream& operator << (std::ostream& os, const Turn& _turn);
};

#endif /* Turn_h */