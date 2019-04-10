//
// Created by loic on 4/6/19.
//

#ifndef EXCEPTION_INVALID_ARGUMENT_H
#define EXCEPTION_INVALID_ARGUMENT_H

#include <stdexcept>
#include <string>

class Exception_invalid_argument : public std::invalid_argument{

public:
    explicit Exception_invalid_argument(const std::string& what): invalid_argument(what){};
    explicit Exception_invalid_argument(const char* what): invalid_argument(what){};
};

#endif //EXCEPTION_INVALID_ARGUMENT_H
