//
// Created by loic on 4/2/19.
//

#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include "Exception_out_of_range.h"
#include "Exception_length_error.h"
#include "Exception_invalid_argument.h"
#include "Exception_bad_alloc.h"
#include "overflowManagement.h"
#include <iostream>
#include <vector>


template <typename T>
Vecteur<T>::Vecteur() : data(std::vector<T>(0)) {};

template <typename T>
Vecteur<T>::Vecteur(size_t n) : data(std::vector<T>(n)) {}

template <typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vector) : data(vector) {}



template <typename T>
T Vecteur<T>::at(size_t n) const {
    try {
        return data.at(n);
    }catch(const std::out_of_range& e){
        throw Exception_out_of_range("Vecteur : n is out of range");
    }
}

template <typename T>
T& Vecteur<T>::at(size_t n){
    try {
        return data.at(n);
    }catch(const std::out_of_range& e){
        throw Exception_out_of_range("Vecteur : n is out of range");
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
        throw Exception_length_error("Vecteur : size can't be greater than the maximum number of elements the vecteur can hold");
    } catch(const std::bad_alloc& e) {
        throw Exception_bad_alloc("Vecteur : Impossible to allocate the memory ask");
    }
}

template <typename T>
T Vecteur<T>::somme() const {
    // Error if our vecteur is empty
    if(!this->size()){
        throw Exception_length_error("Vecteur : Impossible to sum an empty Vecteur");
    }

    T sum = this->at(0);
    for(size_t i = 1; i < this->size(); ++i){
        if(isAnAddOverflow(sum, this->at(i))) {
            throw Exception_overflow_error("Vecteur : Overflow detected in the computed result");
        }
        sum += this->at(i);
    }

    return sum;
}

template <typename T>
Vecteur<T>& Vecteur<T>::operator*(const T& val){
    if(!this->size())
        throw Exception_length_error("Vecteur : impossible to multiply an empty vecteur with a value");

    for(size_t i = 0; i< this->size(); ++i) {
        if(isAMultiplyOverflow(this->at(i), val)) {
            throw Exception_overflow_error("Vecteur : Overflow detected in the computed result");
        }
        this->at(i) = this->at(i)*val;
    }

    return *this;
}

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur& rhs){

    Vecteur<T> result(this->size());

    if(!this->size() || !rhs.size())
        throw Exception_length_error("Vecteur : impossible to multiply an empty vecteur with a another vecteur.");

    if(this->size() != rhs.size())
        throw Exception_invalid_argument("Vecteur : impossible to multiply vecteurs of different size.");

    for(size_t i = 0; i< this->size(); ++i) {
        if(isAMultiplyOverflow(this->at(i), rhs.at(i))) {
            throw Exception_overflow_error("Vecteur : Overflow detected in the computed result");
        }
        result.at(i) = this->at(i) * rhs.at(i);
    }

    return result;

}

template<typename T>
Vecteur<T> Vecteur<T>::operator+ (const Vecteur<T>& rhs) {
    // Error if one of the two vecteur is empty
    if(!this->size() || !rhs.size()){
        throw Exception_length_error("Vecteur : Impossible to sum those vecteur if one or more is empty");
    }
    // Error if both vecteur don't have same size
    if(this->size() != rhs.size()){
        throw Exception_invalid_argument("Vecteur : Both vecteur must have the same size");
    }

    Vecteur res(size());
    for(size_t i = 0; i < this->size(); ++i) {
        if(isAnAddOverflow(this->at(i), rhs.at(i))){
            throw Exception_overflow_error("Vecteur : Overflow detected in the computed result");
        }
        res.at(i) = this->at(i) + rhs.at(i);
    }

    return res;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator- (const Vecteur<T>& rhs) {
    // Error if one of the two vecteur is empty
    if(!this->size() || !rhs.size()){
        throw Exception_length_error("Vecteur : Impossible to sum those vecteur if one or more is empty");
    }
    // Error if both vecteur don't have same size
    if(this->size() != rhs.size()){
        throw Exception_invalid_argument("Vecteur : Both vecteur must have the same size");
    }

    Vecteur res(size());
    for(size_t i = 0; i < this->size(); ++i) {
        if(isASubOverflow(this->at(i), rhs.at(i))) {
            throw Exception_overflow_error("Vecteur : Overflow detected in the computed result");
        }
        res.at(i) = this->at(i) - rhs.at(i);
    }

    return res;
}

#endif //VECTEURIMPL_H
