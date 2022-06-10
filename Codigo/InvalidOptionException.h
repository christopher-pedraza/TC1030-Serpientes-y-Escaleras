/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
InvalidOptionException.h
*****************************************************/

#ifndef InvalidOptionException_h
#define InvalidOptionException_h

#include <iostream>


class InvalidOptionException: public std::exception {
  public:
    const char * what();
    std::string message(int _attempts);
};

#endif /* InvalidOptionException_h */