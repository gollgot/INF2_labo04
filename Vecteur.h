//
// Created by loic on 4/2/19.
//

#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>

template <typename T>
class Vecteur {

public:
    Vecteur<T>(size_t n);
    Vecteur<T>(const std::vector<T>& vector);

private:
    std::vector<T> data;
};

#include "VecteurImpl.h"

#endif //VECTEUR_H
