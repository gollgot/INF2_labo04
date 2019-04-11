/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Creation des classes Vecteurs et Matrices, en implementant les exceptions et la genericite.

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include <limits>
#include "Vecteur.h"
#include "Matrice.h"

using namespace std;

void testVecteur(){

    cout << "----- Tests of Vecteur constructors" << endl;

    Vecteur<int> defaultVecteur;
    cout << "Constructor by default : " << defaultVecteur << endl;

    Vecteur<int> sizeVecteur(3);
    cout << "Constructor with size parameter : " << sizeVecteur << endl;

    vector<int> vectorContent {1,1,1};
    Vecteur<int> vectorVecteur(vectorContent);
    cout << "Constructor with vector parameter : " << vectorVecteur << endl;

    cout << endl << "---- Instanciation of Vecteurs to test" << endl;

    vector<int> contentTest {1,2,3};
    Vecteur<int> vTest(contentTest);
    cout << "vTest = " << vTest << " (normal Vecteur)" << endl;

    Vecteur<int> vEmpty;
    cout << "vEmpty = " << vEmpty << endl;

    vector<int> contentDiffSize {8,9};
    Vecteur<int> vDiffSize(contentDiffSize);
    cout << "vDiffSize = " << vDiffSize << endl;

    vector<int> contentOverflow {1,2,std::numeric_limits<int>::max(), 0};
    Vecteur<int> vOverflow(contentOverflow);
    cout << "vOverflow = " << vOverflow << endl;

    cout << endl << "----- Test of Vecteur methods" << endl;

    cout << "Read vTest at position 0 : " << vTest.at(0) << endl;
    //vTest.at(10);

    vTest.at(2) = 4;
    cout << "After writing 4 in vTest at position 2 : " << vTest << endl;
    //vTest.at(10) = 4;

    cout << "Size of vTest : " << vTest.size() << endl;

    vTest.resize(4);
    cout << "After resizing vTest from 3 to 4 : " << vTest << endl;
    //vTest.resize(-2);

    cout << "Somme of elements in vTest : " << vTest.somme() << endl;
    //vOverflow.somme();

    cout << "vTest * 2 : " << vTest*2 << endl;
    //vEmpty*2;
    //^ Exception: multiplying an empty Vecteur
    //vOverflow*2;
    //^ Exception: overflow

    cout << "vTest * vTest : " << vTest*vTest << endl;
    //vTest*vEmpty;
    //vTest*vDiffSize;
    //vTest*vOverflow;

    cout << "vTest + vTest : " << vTest+vTest << endl;
    //vTest+vEmpty;
    //vTest+vDiffSize;
    //vTest+vOverflow;

    cout << "vTest - vTest : " << vTest-vTest << endl;
    //vTest-vEmpty;
    //vTest-vDiffSize;
    //(vOverflow*(-1))-vTest;

}

void testMatrice(){

    cout << "----- Tests of Matrice constructors" << endl;

    Matrice<int> defaultMatrice;
    cout << "Constructor by default : " << defaultMatrice << endl;

    Matrice<int> rowsMatrice(3);
    cout << "Constructor with rows parameter : " << rowsMatrice << endl;

    Matrice<int> rowsColumnsMatrice(2, 3);
    cout << "Constructor with rows and columns parameters : " << rowsColumnsMatrice << endl;
    //Matrice<int> row0ColumnsMatrice(0, 3);
    //Matrice<int> negativeRowColumnsMatrice(-2, 3);
    //Matrice<int> rowNegativeColumnsMatrice(2, -3);

    cout << endl << "---- Instanciation of Matrices to test" << endl;

    // mTests is Reguliere then become not Reguliere after resizing and return to Reguliere to test operations
    Matrice<int> mTest(2,3);
    Vecteur<int> mTestRow0{vector<int>{1,2,3}};
    mTest.at(0) = mTestRow0;
    cout << "mTest = " << mTest << endl;

    Matrice<int> m2x2(2,2);
    Vecteur<int> m2x2Row0{vector<int>{1,2}};
    m2x2.at(0) = m2x2Row0;
    Vecteur<int> m2x2Row1{vector<int>{3,4}};
    m2x2.at(1) = m2x2Row1;
    cout << "m2x2 = " << m2x2 << endl;

    Matrice<int> m1x3(1,3);
    Vecteur<int> m1x3Row0{vector<int>{1,2,3}};
    m1x3.at(0) = m1x3Row0;
    cout << "m1x3 = " << m1x3 << endl;

    Matrice<int> mEmpty;
    cout << "mEmpty = " << mEmpty << endl;

    Matrice<int> mReguliere(2,3);
    Vecteur<int> mReguliereRow0{vector<int>{1,2,3}};
    mReguliere.at(0) = mReguliereRow0;
    Vecteur<int> mReguliereRow1{vector<int>{4,5,6}};
    mReguliere.at(1) = mReguliereRow1;
    cout << "mReguliere = " << mReguliere << endl;

    Matrice<int> mOverflow(2,2);
    Vecteur<int> mOverflowRow0{vector<int>{1,std::numeric_limits<int>::max()}};
    mOverflow.at(0) = mOverflowRow0;
    Vecteur<int> mOverflowRow1{vector<int>{3,std::numeric_limits<int>::max()}};
    mOverflow.at(1) = mOverflowRow1;
    cout << "mOverflow = " << mOverflow << endl;

    Matrice<int> mToResize(1,2);
    Vecteur<int> mToResizeRow0{vector<int>{1,2}};
    m2x2.at(0) = mToResizeRow0;
    cout << "mToResize = " << mToResize << endl;


    cout << endl << "----- Test of Matrice methods" << endl;

    cout << "Read mTest at row 0 : " << mTest.at(0) << endl;
    //mTest.at(10);
    cout << "Read mTest at row 0, column 1 : " << mTest.at(0).at(1) << endl;
    //mTest.at(0).at(10);

    Vecteur<int> mTestRow1{vector<int>{4,5,6}};
    mTest.at(1) = mTestRow1;
    cout << "After writing [4, 5, 6] in mTest at row 1 : " << mTest << endl;
    //mTest.at(10) = mTestRow1;
    mTest.at(1).at(2) = 7;
    cout << "After writing 7 in mTest at row 1, column 2 : " << mTest << endl;
    //mTest.at(1).at(10) = 7;

    cout << "Size of mTest (Nb of rows) : " << mTest.size() << endl;

    mTest.resize(3);
    cout << "After resizing mTest from 2 rows to 3 : " << mTest << endl;
    //vTest.resize(-2);
    mToResize.resize(2, 5);
    cout << "After resizing mToResize from 2 columns to 5 : " << mTest << endl;
    //mToResize.resize(4, -2);
    cout << endl;

    cout << "mTest is vide? " << boolalpha << mTest.estVide() << endl;
    cout << "mEmpty is vide? " << boolalpha << mEmpty.estVide() << endl;
    cout << endl;

    cout << "mTest is carree? " << boolalpha << mTest.estCarree() << endl;
    cout << "m2x2 is carree? " << boolalpha << m2x2.estCarree() << endl;
    cout << "mEmpty is carree? " << boolalpha << mEmpty.estCarree() << endl;
    cout << endl;

    cout << "mTest is Reguliere? " << boolalpha << mTest.estReguliere() << endl;
    cout << "mReguliere is Reguliere? " << boolalpha << mReguliere.estReguliere() << endl;
    cout << "m2x2 is Reguliere? " << boolalpha << m2x2.estReguliere() << endl;
    cout << "mEmpty is Reguliere? " << boolalpha << mEmpty.estReguliere() << endl;
    cout << endl;

    cout << "Somme of each rows in mReguliere : " << mReguliere.sommeLigne() << endl;
    //mEmpty.sommeLigne();
    //mTest.sommeLigne();
    //mOverflow.sommeLigne();

    cout << "Somme of each columns in mReguliere : " << mReguliere.sommeColonne() << endl;
    //mEmpty.sommeColonne();
    //mTest.sommeColonne();
    //mOverflow.sommeColonne();

    cout << "Somme of diagonal left to right in m2x2 : " << m2x2.sommeDiagonaleGD() << endl;
    //mEmpty.sommeDiagonaleGD();
    //mTest.sommeDiagonaleGD();
    //mOverflow.sommeDiagonaleGD();

    cout << "Somme of diagonal right to left in m2x2 : " << m2x2.sommeDiagonaleDG() << endl;
    //mEmpty.sommeDiagonaleDG();
    //mTest.sommeDiagonaleDG();
    //mOverflow.sommeDiagonaleDG();
    cout << endl;

    cout << "mReguliere * 2 : " << mReguliere*2 << endl;
    //mEmpty*2;
    //mOverflow*2;
    cout << endl;

    // resizing mTest to test arithmetic operations between Matrices
    mTest.resize(2, 3);
    cout << "Matrice lhs (mTest): " << mTest << endl;
    cout << "Matrice rhs (mReguliere): " << mReguliere << endl;



    cout << "lhs*rhs = " << mTest*mReguliere << endl;
    //mTest*mEmpty;
    //mTest*m1x3;
    //mTest*m2x2;
    //m2x2*mOverflow;

    cout << "lhs+rhs = " << mTest+mReguliere << endl;
    //mTest+mEmpty;
    //mTest+m1x3;
    //mTest+m2x2;
    //m2x2+mOverflow;

}

int main() {

    testVecteur();
    //testMatrice();

    return 0;
}