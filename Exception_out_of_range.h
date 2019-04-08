//
// Created by Rosalie Chhen on 04.04.2019.
//

#ifndef VECTEUR_OUT_OF_RANGE_H
#define VECTEUR_OUT_OF_RANGE_H

#include <stdexcept>
#include <string>

class Exception_out_of_range : public std::logic_error{

public:
    explicit Exception_out_of_range(const std::string& what): logic_error(what){};
    explicit Exception_out_of_range(const char* what): logic_error(what){};
};

#endif //VECTEUR_OUT_OF_RANGE_H
