//
// Created by loic on 4/2/19.
//

#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include "vecteurException_out_of_range.h"
#include "vecteurException_length_error.h"
#include "vecteurException_invalid_argument.h"
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
        throw vecteurException_out_of_range("Vecteur : n is out of range");
    }

    return val;
}

template <typename T>
T& Vecteur<T>::at(size_t n){
    try {
        T& val = data.at(n);
        return val;
    }catch(const std::out_of_range& e){
        throw vecteurException_out_of_range("Vecteur : n is out of range");
    }
}

template <typename T>
size_t Vecteur<T>::size() const noexcept {
    return data.size();
}

template <typename T>
void Vecteur<T>::resize(size_t size) {
    try {
        data.resize(size);
    } catch(const std::length_error& e) {
        throw vecteurException_invalid_argument("Vecteur : new size can't be negative");
    }
}

template <typename T>
T Vecteur<T>::somme() const {
    if(data.empty()){
        throw vecteurException_length_error("Vecteur : Impossible to sum an empty vecteur");
    }

    T sum = data[0];
    for(size_t i = 1; i < data.size(); ++i){
        sum += data.at(i);
    }

    return sum;
}

#endif //VECTEURIMPL_H
