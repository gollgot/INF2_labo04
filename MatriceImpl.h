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
    if((l == 0) and (c > l)){
        throw Exception_invalid_argument("Matrice : If rows size is 0, the columns size can't be greater than 0");
    }

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

template<typename T>
bool Matrice<T>::estVide() const noexcept {
    bool rowsEmpty = (bool)!this->size();
    bool columnsEmpty = true;

    for(size_t row = 0; row < this->size(); ++row) {
        if(buffer.at(row).size() > 0){
            columnsEmpty = false;
        }
    }

    return (rowsEmpty && columnsEmpty);
}

template<typename T>
bool Matrice<T>::estCarree() const noexcept {
    bool isSquareMatrix = true;
    size_t rowsSize = this->size();
    size_t columnSize = 0;

    if(!this->estVide()) {
        for (size_t row = 0; row < rowsSize; ++row) {
            columnSize = buffer.at(row).size();
            if(columnSize != rowsSize){
                isSquareMatrix = false;
                break;
            }
        }
    }

    return isSquareMatrix;
}

template<typename T>
bool Matrice<T>::estReguliere() const noexcept {
    bool isRegularMatrix = true;

    if(!this->estVide()) {
        size_t firstRowSize = buffer.at(0).size();
        for (size_t row = 1; row < this->size(); ++row) {
            if(firstRowSize != buffer.at(row).size()){
                isRegularMatrix = false;
                break;
            }
        }
    }

    return isRegularMatrix;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeLigne() const {
    if(this->estVide()) {
        throw Exception_length_error("Matrice : Impossible to sum an empty Matrice");
    }
    if(!this->estReguliere()){
        throw Exception_length_error("Matrice : Impossible to sum rows of an irregular Matrice");
    }

    try {

        Vecteur<T> sum(this->size());
        for (size_t row = 0; row < this->size(); ++row) {
            sum.at(row) = this->at(row).somme();
        }
        return sum;

    }catch(const Exception_length_error& e){
        throw Exception_length_error("Matrice : Impossible to sum an empty row");
    }
}

#endif //MATRICEIMPL_H
