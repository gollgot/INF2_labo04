//
// Created by Rosalie Chhen on 04.04.2019.
//

#ifndef VECTEUR_OUT_OF_RANGE_H
#define VECTEUR_OUT_OF_RANGE_H

#include <stdexcept>
#include <string>

class vecteur_out_of_range : public std::out_of_range{

public:
    explicit vecteur_out_of_range(const std::string& what): out_of_range(what){};
    explicit vecteur_out_of_range(const char* what): out_of_range(what){};
};

#endif //ECTEUR_OUT_OF_RANGE_H
