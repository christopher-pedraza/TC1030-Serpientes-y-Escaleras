/****************************************************
TC1030 - Equipo 8
SerpientesEscaleras
InvalidConfigurationException.h
*****************************************************/

#ifndef InvalidConfigurationException_h
#define InvalidConfigurationException_h

#include <iostream>


class InvalidConfigurationException: public std::exception {
  public:
    const char * what();
    std::string config(std::string param_name, int param_value);
};

#endif /* InvalidConfigurationException_h */