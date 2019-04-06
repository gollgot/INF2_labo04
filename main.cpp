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


    monVecteur.at(0) = 19;

    cout << monVecteur << endl;
    try {
        monVecteur.resize(-3);
    } catch(const vecteurException_length_error& e) {
        cout << e.what();
    }



    /*
    cout << "---------------" << endl;

    vector<int> v {1,2,3};
    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;
    //try {
        v.resize(-10);


    cout << "Size : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

    for(int val : v) {
        cout << val << ", ";
    }


    // cout << monVecteur.at(6) << endl;

*/


    return 0;
}