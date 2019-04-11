/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : Exception_out_of_range
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les déclarations / definitions de metodes, attributs, constructeurs de la classe Exception_out_of_range

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef EXCEPTION_OUT_OF_RANGE_H
#define EXCEPTION_OUT_OF_RANGE_H

#include <stdexcept>
#include <string>

class Exception_out_of_range : public std::out_of_range{

public:
    /**
     * @brief Constructor with string parameter
     * @param what The error message
     */
    explicit Exception_out_of_range(const std::string& what): out_of_range(what){};
    /**
     * @brief Constructor with char* parameter
     * @param what The error message
     */
    explicit Exception_out_of_range(const char* what): out_of_range(what){};
};

#endif //EXCEPTION_OUT_OF_RANGE_H
