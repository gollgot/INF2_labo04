//
// Created by loic on 4/2/19.
//

#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include "vecteur_out_of_range.h"
#include <iostream>
#include <vector>


template <typename T>
Vecteur<T>::Vecteur(size_t n) noexcept : data(std::vector<T>(n)) {}

template <typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vector) noexcept : data(vector) {}


template <typename T>
T Vecteur<T>::at(size_t n) const {
    T val;
    try {
        val = data.at(n);
    }catch(const std::out_of_range& e){
        throw vecteur_out_of_range("n is out of range");
    }

    return val;
}

template <typename T>
T& Vecteur<T>::at(size_t n){
    T val;
    try {
        val = data.at(n);
    }catch(const std::out_of_range& e){
        throw vecteur_out_of_range("n is out of range");
    }
    return val;
}

template <typename T>
size_t Vecteur<T>::size() const noexcept {
    return data.size();
}


#endif //VECTEURIMPL_H
