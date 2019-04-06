//
// Created by loic on 4/6/19.
//

#ifndef VECTEUREXCEPTION_LENGTH_ERROR_H
#define VECTEUREXCEPTION_LENGTH_ERROR_H

#include <stdexcept>
#include <string>

class vecteurException_length_error : public std::logic_error{

public:
    explicit vecteurException_length_error(const std::string& what): logic_error(what){};
    explicit vecteurException_length_error(const char* what): logic_error(what){};
};

#endif //VECTEUREXCEPTION_LENGTH_ERROR_H
