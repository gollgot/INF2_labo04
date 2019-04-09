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
#include <limits>
#include "Vecteur.h"
#include "Matrice.h"

using namespace std;


int main() {

    vector<int> test {1,4,5};

    Vecteur<int> monVecteur(test);

    //cout << monVecteur.at(20) << endl;
    monVecteur.at(0) = 10;

    cout << monVecteur << endl;

    //monVecteur.resize(-3);
    monVecteur.resize(2);

    cout << monVecteur << endl;

    cout << monVecteur.somme() << endl;
    vector<int> a;
    Vecteur<int> v(a);
    monVecteur = v;
    cout << monVecteur << endl;
    //cout << monVecteur.somme() << endl;


    vector<int> test1 {3,5,6};
    vector<int> test2 {4,5,6};
    Vecteur<int> monVecteur1(test1);
    Vecteur<int> monVecteur2(test2);
    cout << (monVecteur1 + monVecteur2) << endl;
    cout << (monVecteur1 - monVecteur2) << endl;
    cout << monVecteur1 * 2 << endl;
    cout << monVecteur1 * monVecteur2 << endl;

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

    Matrice<int> matrice1(3,5);
    Vecteur<int> in{vector<int>{1,2,3,4,5}};
    cout << matrice1.size() << endl;
    matrice1.at(2) = in;
    cout << matrice1 << endl;

    matrice1.at(0).at(4) = 20;
    cout << matrice1 << endl;

    matrice1.resize(6);
    cout << matrice1 << endl;

    matrice1.resize(2, 0);
    matrice1.at(0) = Vecteur<int> {vector<int>{2,3,4}};
    matrice1.at(1) = Vecteur<int> {vector<int>{1,5,2}};
    cout << matrice1 << endl;

    cout << "Matrice vide ? " << boolalpha << matrice1.estVide() << noboolalpha << endl;

    cout << "Matrice carree ? " << boolalpha << matrice1.estCarree() << noboolalpha << endl;

    cout << "Matrice reguliere ? " << boolalpha << matrice1.estReguliere() << noboolalpha << endl;

    cout << matrice1.sommeLigne() << endl;

    return 0;
}