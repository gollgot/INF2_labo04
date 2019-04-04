//
// Created by loic on 4/2/19.
//

#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>

template <typename T>
class Vecteur {

public:
    Vecteur<T>(size_t n) noexcept;
    Vecteur<T>(const std::vector<T>& vector) noexcept;

    // Read
    T at(size_t n) const;
    // Write
    T& at(size_t n);
    size_t size() const;
    void resize(size_t size);
    T somme() const;


    friend std::ostream& operator<<(std::ostream& os, const Vecteur& rhs);

    Vecteur<T>& operator*(const T& val);
    Vecteur<T>& operator*(const Vecteur& rhs);
    Vecteur<T>& operator+(const Vecteur& rhs);
    Vecteur<T>& operator-(const Vecteur& rhs);


private:
    std::vector<T> data;
};

#include "VecteurImpl.h"

#endif //VECTEUR_H
