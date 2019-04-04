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
    cout << monVecteur << endl;


    // cout << monVecteur.at(6) << endl;

    

    return 0;
}