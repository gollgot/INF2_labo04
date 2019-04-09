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
            this->at(i).resize(columns);
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
            this->at(row).resize(c);
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
        if(this->at(row).size() > 0){
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
            columnSize = this->at(row).size();
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
        size_t firstRowSize = this->at(0).size();
        for (size_t row = 1; row < this->size(); ++row) {
            if(firstRowSize != this->at(row).size()){
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
        throw Exception_length_error("Matrice : Impossible to sum rows of an empty Matrice");
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

template<typename T>
Vecteur<T> Matrice<T>::sommeColonne() const {
    if(this->estVide()) {
        throw Exception_length_error("Matrice : Impossible to sum columns of an empty Matrice");
    }
    if(!this->estReguliere()){
        throw Exception_length_error("Matrice : Impossible to sum columns of an irregular Matrice");
    }

    try {

        Vecteur<T> sum(this->at(0).size());
        for (size_t row = 0; row < this->size(); ++row) {
            for(size_t column = 0; column < this->at(row).size(); ++column){
                sum.at(column) = sum.at(column) + this->at(row).at(column);
            }
        }
        return sum;

    }catch(const Exception_length_error& e){
        throw Exception_length_error("Matrice : Impossible to sum an empty column");
    }
}

template<typename T>
T Matrice<T>::sommeDiagonaleGD() const {
    if(this->estVide()){
        throw Exception_length_error("Matrice : Impossible to sum the left to right diagonal of an empty Matrice");
    }
    if(!this->estCarree()){
        throw Exception_length_error("Matrice : Impossible to sum the left to right diagonal of a no square Matrice");
    }

    T sum = this->at(0).at(0);
    for(size_t i = 1; i < this->size(); ++i){
        sum += this->at(i).at(i);
    }

    return sum;
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() const {
    if(this->estVide()){
        throw Exception_length_error("Matrice : Impossible to sum the right to left diagonal of an empty Matrice");
    }
    if(!this->estCarree()){
        throw Exception_length_error("Matrice : Impossible to sum the right to left diagonal of a no square Matrice");
    }

    const size_t DIMENSION = this->size();
    T sum = this->at(0).at(DIMENSION - 1);

    for(size_t row = 1; row < DIMENSION; ++row){
        sum += this->at(row).at(DIMENSION - row - 1);
    }

    return sum;
}

#endif //MATRICEIMPL_H
