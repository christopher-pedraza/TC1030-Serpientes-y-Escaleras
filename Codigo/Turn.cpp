/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
Turn.cpp
*****************************************************/

#include "Turn.h"

Turn::Turn() {
    turn        = 0;
    diceNumber  = 0;
    playerInfo  = " ";
    newTile     = ' ';
    boardTile   = ' ';
}

Turn::Turn(int _turn, int _diceNumber, std::string _playerInfo, char _newTile, char _boardTile) {
    turn        = _turn;
    diceNumber  = _diceNumber;
    playerInfo  = _playerInfo;
    newTile     = _newTile;
    boardTile   = _boardTile;
}

void Turn::setTurn(int _turn) {
    turn = _turn;
}

void Turn::setDiceNumber(int _diceNumber) {
    diceNumber = _diceNumber;
}

void Turn::setPlayerInfo(std::string _playerInfo) {
    playerInfo = _playerInfo;
}

void Turn::setNewTile(int _newTile) {
    newTile = _newTile;
}

void Turn::setBoardTile(char _boardTile) {
    boardTile = _boardTile;
}

std::ostream& operator << (std::ostream& os, const Turn& _turn) {
    os << std::to_string(_turn.turn) << " " << _turn.playerInfo << " " << _turn.diceNumber << " " << _turn.boardTile << " " << _turn.newTile << std::endl;
    return os;
}