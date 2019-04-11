/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : overflowManagement.h
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les déclarations / definitions de fonctions en relation avec la gestion de l'overflow

Remarque(s) : Pour la gestion de l overflow, nous nous somme basé sur ce que nous avons appris en cours ARO1.
              en regardant les signes des valeurs A et B ainsi que du résultat de l'addition ou soustraction,
              nous pouvons savoir si il y a eu un overflow ou non.

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef OVERFLOWMANAGEMENT_H
#define OVERFLOWMANAGEMENT_H

#include "Exception_overflow_error.h"

/**
 * @brief  Check if the sum between the parameters is an overflow
 * @tparam T Generic type
 * @param lhs The left value
 * @param rhs The right value
 *
 * @return True if there is an overflow, false otherwise
 */
template <typename T>
bool isAnAddOverflow(const T& lhs, const T& rhs) {
    T defaultVal = T();
    return ((lhs >= defaultVal) and (rhs >= defaultVal) and ((lhs + rhs) < defaultVal))
            or
            ((lhs < defaultVal) and (rhs < defaultVal) and ((lhs + rhs) >= defaultVal));
}

/**
 * @brief  Check if the subtraction between the parameters is an overflow
 * @tparam T Generic type
 * @param lhs The left value
 * @param rhs The right value
 *
 * @return True if there is an overflow, false otherwise
 */
template <typename T>
bool isASubOverflow(const T& lhs, const T& rhs) {
    T defaultVal = T();
    return ((lhs >= defaultVal) and (rhs < defaultVal) and ((lhs - rhs) < defaultVal))
            or
            ((lhs < defaultVal) and (rhs >= defaultVal) and ((lhs - rhs) >= defaultVal));
}

/**
 * @brief  Check if the multiplication between the parameters is an overflow
 * @tparam T Generic type
 * @param lhs The left value
 * @param rhs The right value
 *
 * @return True if there is an overflow, false otherwise
 *
 * @details A multiplication is many addition : e.g 5*2 is 2 + 2 + 2 + 2 + 2
 */
template <typename T>
bool isAMultiplyOverflow(const T& lhs, const T& rhs){
    T intermediateResult = lhs;
    T begin = T();
    for(T i = ++begin; i < rhs; ++i) {
        if(isAnAddOverflow(intermediateResult, lhs)) {
            return true;
        }
        intermediateResult += lhs;
    }

    return false;
}

#endif //OVERFLOWMANAGEMENT_H
