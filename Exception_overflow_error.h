//
// Created by loic on 4/10/19.
//

#ifndef EXCEPTION_OVERFLOW_ERROR_H
#define EXCEPTION_OVERFLOW_ERROR_H

#include <stdexcept>

class Exception_overflow_error : public std::overflow_error{

public:
    explicit Exception_overflow_error(const std::string& what): overflow_error(what){};
    explicit Exception_overflow_error(const char* what): overflow_error(what){};
};

#endif //EXCEPTION_OVERFLOW_ERROR_H
