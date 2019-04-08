//
// Created by loic on 4/4/19.
//

#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include "Vecteur.h"

template <typename T>
class Matrice {

public:
    Matrice<T>();
    Matrice(size_t rows);
    Matrice<T>(size_t rows, size_t columns);

private:
    Vecteur<Vecteur<T>> buffer;
};

#include "MatriceImpl.h"

#endif //MATRICE_H
