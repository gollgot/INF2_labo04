//
// Created by loic on 4/6/19.
//

#ifndef EXCEPTION_LENGTH_ERROR_H
#define EXCEPTION_LENGTH_ERROR_H

#include <stdexcept>
#include <string>

class Exception_length_error : public std::length_error{

public:
    explicit Exception_length_error(const std::string& what): length_error(what){};
    explicit Exception_length_error(const char* what): length_error(what){};
};

#endif //EXCEPTION_LENGTH_ERROR_H
