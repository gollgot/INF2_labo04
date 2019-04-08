//
// Created by loic on 4/6/19.
//

#ifndef VECTEUREXCEPTION_INVALID_ARGUMENT_H
#define VECTEUREXCEPTION_INVALID_ARGUMENT_H

#include <stdexcept>
#include <string>

class Exception_invalid_argument : public std::logic_error{

public:
    explicit Exception_invalid_argument(const std::string& what): logic_error(what){};
    explicit Exception_invalid_argument(const char* what): logic_error(what){};
};

#endif //VECTEUREXCEPTION_INVALID_ARGUMENT_H
