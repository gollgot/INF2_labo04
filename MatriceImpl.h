/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : MatriceImpl.h
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les definitions attributs, constructeurs de la classe MatriceImpl

Remarque(s) : Tous les commentaires relatifs aux methodes sont dans le header qui contient les declarations

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef MATRICEIMPL_H
#define MATRICEIMPL_H

#include "Vecteur.h"
#include "Exception_out_of_range.h"
#include "Exception_length_error.h"
#include "Exception_invalid_argument.h"
#include "Exception_bad_alloc.h"
#include "overflowManagement.h"




template<typename T>
Matrice<T>::Matrice():buffer(Vecteur<Vecteur<T>>(0)) {}

template<typename T>
Matrice<T>::Matrice(size_t rows) {
    try{
        buffer = Vecteur<Vecteur<T>>(rows);
    } catch(const Exception_length_error& e) {
        throw Exception_length_error("Matrice : size can't be greater than the maximum number of elements the rows can hold\n" + std::string(e.what()));
    } catch(const Exception_bad_alloc& e) {
        throw Exception_bad_alloc("Matrice : Impossible to allocate the memory ask\n" + std::string(e._what()));
    }
}

template<typename T>
Matrice<T>::Matrice(size_t rows, size_t columns){
    if((rows == 0) and (columns > rows)){
        throw Exception_invalid_argument("Matrice : If rows size is 0, the columns size can't be greater than 0");
    }

    try {
        buffer = Vecteur<Vecteur<T>>(rows);
        // We fill our buffer with empty rows, now we resize all rows with columns nb
        for (size_t i = 0; i < rows; ++i) {
            this->at(i).resize(columns);
        }
    }catch(const Exception_length_error& e){
        throw Exception_length_error("Matrice : size can't be greater than the maximum number of elements the row can hold\n" + std::string(e.what()));
    }catch(const Exception_bad_alloc& e){
        throw Exception_bad_alloc("Matrice : Impossible to allocate the memory ask\n" + std::string(e._what()));
    }
}



template<typename T>
Vecteur<T> Matrice<T>::at(size_t n) const {
    try {
        return buffer.at(n);
    }catch(const Exception_out_of_range& e) {
        throw(Exception_out_of_range("Matrice : n is out of range\n" + std::string(e.what())));
    }
}

template<typename T>
Vecteur<T>& Matrice<T>::at(size_t n) {
    try {
        return buffer.at(n);
    }catch(const Exception_out_of_range& e) {
        throw(Exception_out_of_range("Matrice : n is out of range\n" + std::string(e.what())));
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
    } catch(const Exception_length_error& e) {
        throw Exception_length_error("Matrice : size can't be greater than the maximum number of elements the vecteur can hold\n" + std::string(e.what()));
    } catch(const Exception_bad_alloc& e) {
        throw Exception_bad_alloc("Matrice : Impossible to allocate the memory ask\n" + std::string(e.what()));
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
    } catch(const Exception_length_error& e) {
        throw Exception_length_error("Matrice : size can't be greater than the maximum number of elements the vecteur can hold\n" + std::string(e.what()));
    } catch(const Exception_bad_alloc& e) {
        throw Exception_bad_alloc("Matrice : Impossible to allocate the memory ask\n" + std::string(e.what()));
    }
}

template<typename T>
bool Matrice<T>::estVide() const noexcept {
    return (bool)!this->size();
}

template<typename T>
bool Matrice<T>::estCarree() const noexcept {
    if(!estReguliere()){
        return false;
    }

    return estVide() or (this->size() == this->at(0).size());
}

template<typename T>
bool Matrice<T>::estReguliere() const noexcept {
    bool isRegularMatrix = true;

    if(!this->estVide()) {
        for (size_t row = 1; row < this->size(); ++row) {
            if(this->at(row-1).size() != this->at(row).size()){
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
        throw Exception_length_error("Matrice : Impossible to sum columns of an empty Matrice");
    }

    try {

        Vecteur<T> sum(this->size());
        for (size_t row = 0; row < this->size(); ++row) {
            sum.at(row) = this->at(row).somme();
        }
        return sum;

    }catch(const Exception_length_error& e){
        throw Exception_length_error("Matrice : Impossible to sum an empty row\n" + std::string(e.what()));
    }catch(const Exception_overflow_error& e){
        throw Exception_overflow_error("Matrice : Overflow detected in the computed result\n" + std::string(e.what()));
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


    Vecteur<T> sum(this->at(0).size());
    for (size_t row = 0; row < this->size(); ++row) {
        for(size_t column = 0; column < this->at(row).size(); ++column){
            if(isAnAddOverflow(sum.at(column), this->at(row).at(column))) {
                throw Exception_overflow_error("Matrice : Overflow detected in the computed result");
            }
            sum.at(column) += this->at(row).at(column);
        }
    }
    return sum;
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
        if(isAnAddOverflow(sum, this->at(i).at(i))) {
            throw Exception_overflow_error("Matrice : Overflow detected in the computed result");
        }
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
        if(isAnAddOverflow(sum, this->at(row).at(DIMENSION - row - 1))) {
            throw Exception_overflow_error("Matrice : Overflow detected in the computed result");
        }
        sum += this->at(row).at(DIMENSION - row - 1);
    }

    return sum;
}

template <typename T>
Matrice<T> Matrice<T>::operator*(const T& valeur) const {

    // + exception debordement
    if(estVide()){
        throw Exception_length_error("Matrice : Impossible to multiply elements of an empty matrice with a value");
    }

    Matrice<T> result = *this;
    for(size_t i = 0; i< this->size(); ++i){
        try {
            result.at(i) = result.at(i) * valeur;
        } catch (const Exception_overflow_error& e) {
            throw Exception_overflow_error("Matrice : Overflow detected in the computed result\n" + std::string(e.what()));
        }
    }

    return result;

}

template <typename T>
Matrice<T> Matrice<T>::operator*(const Matrice<T>& rhs) const {

    // + exception debordement
    if(estVide() || rhs.estVide()){
        throw Exception_length_error("Matrice : Impossible to multiply an empty matrice with another matrice");
    }

    if(this->size()!= rhs.size()){
        throw Exception_invalid_argument("Matrice : both matrices must have the same numbers of rows to may multiply each other");
    }

    Matrice<T> result = *this;

    for(size_t i = 0; i < this->size(); ++i){

        if(this->at(i).size() != rhs.at(i).size() ){
            throw Exception_invalid_argument("Matrice : each rows of matrices being multiplied must have the same number of elements (columns)");
        }

        try {
            result.at(i) = result.at(i) * rhs.at(i);
        } catch (const Exception_overflow_error& e) {
            throw Exception_overflow_error("Matrice : Overflow detected in the computed result\n" + std::string(e.what()));
        }
    }


    return result;

}

template <typename T>
Matrice<T> Matrice<T>::operator+(const Matrice<T>& rhs) const {

    // + exception debordement
    if(estVide() || rhs.estVide()){
        throw Exception_length_error("Matrice : Impossible to add an empty matrice with another matrice");
    }

    if(this->size()!= rhs.size()){
        throw Exception_invalid_argument("Matrice : both matrices must have the same numbers of rows to may operate an addition");
    }

    Matrice<T> result = *this;

    for(size_t i = 0; i < this->size(); ++i){

        if(this->at(i).size() != rhs.at(i).size() ){
            throw Exception_invalid_argument("Matrice : each rows of matrices being added must have the same number of elements (columns)");
        }

        try {
            result.at(i) = result.at(i) + rhs.at(i);
        } catch (const Exception_overflow_error& e) {
            throw Exception_overflow_error("Matrice : Overflow detected in the computed result\n" + std::string(e.what()));
        }

    }


    return result;

}

#endif //MATRICEIMPL_H
