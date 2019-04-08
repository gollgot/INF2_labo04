//
// Created by loic on 4/4/19.
//

#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include "Vecteur.h"

template <typename T>
class Matrice;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrice<T>& rhs){

    // TODO

    return os;
}

template <typename T>
class Matrice {

public:
    Matrice<T>();
    Matrice(size_t rows);
    Matrice<T>(size_t rows, size_t columns);

    friend std::ostream& operator<< <T>(std::ostream& os, const Matrice<T>& rhs);

private:
    Vecteur<Vecteur<T>> buffer;
};

#include "MatriceImpl.h"

#endif //MATRICE_H
