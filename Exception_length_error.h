/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : Exception_length_error.h
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les déclarations / definitions de metodes, attributs, constructeurs de la classe Exception_length_error

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef EXCEPTION_LENGTH_ERROR_H
#define EXCEPTION_LENGTH_ERROR_H

#include <stdexcept>
#include <string>

class Exception_length_error : public std::length_error{

public:
    /**
     * @brief Constructor with string parameter
     * @param what The error message
     */
    explicit Exception_length_error(const std::string& what): length_error(what){};
    /**
     * @brief Constructor with char* parameter
     * @param what The error message
     */
    explicit Exception_length_error(const char* what): length_error(what){};
};

#endif //EXCEPTION_LENGTH_ERROR_H
