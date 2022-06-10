#include "InvalidConfigurationException.h"

const char * InvalidConfigurationException::what() {
    return "Exception: InvalidConfigurationException";
}

std::string InvalidConfigurationException::config(std::string param_name, int param_value) {
    return "Invalid " + param_name + " value " + std::to_string(param_value);
}