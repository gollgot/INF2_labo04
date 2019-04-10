//
// Created by Rosalie Chhen on 04.04.2019.
//

#ifndef EXCEPTION_OUT_OF_RANGE_H
#define EXCEPTION_OUT_OF_RANGE_H

#include <stdexcept>
#include <string>

class Exception_out_of_range : public std::out_of_range{

public:
    explicit Exception_out_of_range(const std::string& what): out_of_range(what){};
    explicit Exception_out_of_range(const char* what): out_of_range(what){};
};

#endif //EXCEPTION_OUT_OF_RANGE_H
