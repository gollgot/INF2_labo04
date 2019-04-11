/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : Exception_invalid_argument.h
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les déclarations / definitions de metodes, attributs, constructeurs de la classe Exception_invalid_argument

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef EXCEPTION_INVALID_ARGUMENT_H
#define EXCEPTION_INVALID_ARGUMENT_H

#include <stdexcept>
#include <string>

class Exception_invalid_argument : public std::invalid_argument{

public:
    /**
     * @brief Constructor with string parameter
     * @param what The error message
     */
    explicit Exception_invalid_argument(const std::string& what): invalid_argument(what){};
    /**
     * @brief Constructor with char* parameter
     * @param what The error message
     */
    explicit Exception_invalid_argument(const char* what): invalid_argument(what){};
};

#endif //EXCEPTION_INVALID_ARGUMENT_H
