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
    os << "[";
    for(size_t row = 0; row < rhs.size(); ++row) {
        os << rhs.at(row);
    }
    os << "]";

    return os;
}

template <typename T>
class Matrice {

public:
    Matrice<T>();
    Matrice(size_t rows);
    Matrice<T>(size_t rows, size_t columns);

    Vecteur<T> at(size_t n) const;
    Vecteur<T>& at(size_t n);
    size_t size() const noexcept;
    void resize(size_t l);

    friend std::ostream& operator<< <T>(std::ostream& os, const Matrice<T>& rhs);

private:
    Vecteur<Vecteur<T>> buffer;
};

#include "MatriceImpl.h"

#endif //MATRICE_H
