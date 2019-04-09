//
// Created by loic on 4/4/19.
//

#ifndef MATRICEIMPL_H
#define MATRICEIMPL_H

#include "Vecteur.h"
#include "Exception_invalid_argument.h"

template<typename T>
Matrice<T>::Matrice():buffer(Vecteur<Vecteur<T>>(0)) {}

template<typename T>
Matrice<T>::Matrice(size_t rows):buffer(Vecteur<Vecteur<T>>(rows)) {}

template<typename T>
Matrice<T>::Matrice(size_t rows, size_t columns):buffer(Vecteur<Vecteur<T>>(rows)) {
    try {
        // We fill our buffer with empty rows, now we resize all rows with columns nb
        for (size_t i = 0; i < rows; ++i) {
            buffer.at(i).resize(columns);
        }
    }catch(const Exception_invalid_argument& e){
        throw Exception_invalid_argument("Matrice : Impossible to create a matrice with negative column size");
    }
}



template<typename T>
Vecteur<T> Matrice<T>::at(size_t n) const {
    try {
        return buffer.at(n);
    }catch(const Exception_out_of_range& e) {
        throw(Exception_out_of_range("Matrice : n is out of range"));
    }
}

template<typename T>
Vecteur<T>& Matrice<T>::at(size_t n) {
    try {
        return buffer.at(n);
    }catch(const Exception_out_of_range& e) {
        throw(Exception_out_of_range("Matrice : n is out of range"));
    }
}

template<typename T>
size_t Matrice<T>::size() const noexcept {
    return buffer.size();
}

template<typename T>
void Matrice<T>::resize(size_t l) {
    try {
        // Resize rows 
        buffer.resize(l);
    } catch(const std::length_error& e) {
        throw Exception_length_error("Matrice : size can't be greater than the maximum number of elements the vecteur can hold");
    } catch(const std::bad_alloc& e) {
        throw Exception_bad_alloc("Matrice : Impossible to allocate the memory ask");
    }
}

template<typename T>
void Matrice<T>::resize(size_t l, size_t c) {
    try {
        // Resize rows
        buffer.resize(l);

        // Resize columns
        for(size_t row = 0; row < this->size(); ++row){
            buffer.at(row).resize(c);
        }
    } catch(const std::length_error& e) {
        throw Exception_length_error("Matrice : size can't be greater than the maximum number of elements the vecteur can hold");
    } catch(const std::bad_alloc& e) {
        throw Exception_bad_alloc("Matrice : Impossible to allocate the memory ask");
    }
}

#endif //MATRICEIMPL_H
