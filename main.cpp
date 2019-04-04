/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Vecteur
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : -

But         : -

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */


#include <iostream>

#include "Vecteur.h"

using namespace std;


int main() {

    vector<int> test {1,4,5};

    Vecteur<int> monVecteur(test);

    cout << "bla" << endl;


    std::vector<int> an {1,2};
    an.at(0); //1 const
    an.at(0) = 2; //2    pas const T&


    return 0;
}