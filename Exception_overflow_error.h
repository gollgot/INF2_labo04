/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : Exception_bad_alloc.h
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les déclarations / definitions de metodes, attributs, constructeurs de la classe Exception_bad_alloc

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef EXCEPTION_OVERFLOW_ERROR_H
#define EXCEPTION_OVERFLOW_ERROR_H

#include <stdexcept>

class Exception_overflow_error : public std::overflow_error{

public:
    /**
     * @brief Constructor with string parameter
     * @param what The error message
     */
    explicit Exception_overflow_error(const std::string& what): overflow_error(what){};
    /**
     * @brief Constructor with char* parameter
     * @param what The error message
     */
    explicit Exception_overflow_error(const char* what): overflow_error(what){};
};

#endif //EXCEPTION_OVERFLOW_ERROR_H
