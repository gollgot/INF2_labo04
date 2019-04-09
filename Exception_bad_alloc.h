//
// Created by loic on 4/9/19.
//

#ifndef EXCEPTION_BAD_ALLOC_H
#define EXCEPTION_BAD_ALLOC_H

#include <stdexcept>

class Exception_bad_alloc : public std::exception{

public:
    explicit Exception_bad_alloc(const std::string& what): exception(), whatMsg(what){};
    explicit Exception_bad_alloc(const char* what): exception(), whatMsg(what){};

    std::string what2() const {
        return whatMsg;
    }

private:
    std::string whatMsg;
};

#endif //EXCEPTION_BAD_ALLOC_H
