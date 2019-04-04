//
// Created by loic on 4/2/19.
//

#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <vector>

// We have to declare our Vecteur class to be able to use it as a parameter
template<typename T>
class Vecteur;

template <typename T>
std::ostream& operator<< (std::ostream& os, const Vecteur<T>& rhs) noexcept {
    os << "[";
    for(std::size_t i = 0; i < rhs.size(); ++i) {
        if(i > 0) {
            os << ", ";
        }
        os << rhs.at(i);
    }
    os << "]";

    return os;
}


template <typename T>
class Vecteur {

public:
    Vecteur<T>(size_t n) noexcept;
    Vecteur<T>(const std::vector<T>& vector) noexcept;

    // Read
    T at(size_t n) const;
    // Write
    T& at(size_t n);
    size_t size() const noexcept;
    void resize(size_t size);
    T somme() const;

    friend std::ostream& operator<< <T>(std::ostream& os, const Vecteur<T>& rhs) noexcept;

    Vecteur<T>& operator*(const T& val);
    Vecteur<T>& operator*(const Vecteur& rhs);
    Vecteur<T>& operator+(const Vecteur& rhs);
    Vecteur<T>& operator-(const Vecteur& rhs);


private:
    std::vector<T> data;
};

#include "VecteurImpl.h"

#endif //VECTEUR_H
