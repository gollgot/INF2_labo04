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

#endif //MATRICEIMPL_H
