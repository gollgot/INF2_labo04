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
    //^ Exception: read at position 10

    vTest.at(2) = 4;
    cout << "After writing 4 in vTest at position 2 : " << vTest << endl;
    //vTest.at(10) = 4;
    // ^ Exception: writing 4 at position 10

    cout << "Size of vTest : " << vTest.size() << endl;

    vTest.resize(4);
    cout << "After resizing vTest from 3 to 4 : " << vTest << endl;
    //vTest.resize(-2);
    //^ Exception: resizing from 4 to -2

    cout << "Somme of elements in vTest : " << vTest.somme() << endl;
    //vOverflow.somme();
    //^ Exception: somme of vOverflow is greater than numeric_limits<int>::max()

    cout << "vTest * 2 : " << vTest*2 << endl;
    //vEmpty*2;
    //^ Exception: multiplying an empty Vecteur
    //vOverflow*2;
    //^ Exception: overflow

    cout << "vTest * vTest : " << vTest*vTest << endl;
    //vTest*vEmpty;
    //^ Exception: multiplying an empty Vecteur and another Vecteur
    //vTest*vDiffSize;
    //^ Exception: multiplying Vecteurs of different size
    //vTest*vOverflow;
    //^ Exception: overflow

    cout << "vTest + vTest : " << vTest+vTest << endl;
    //vTest+vEmpty;
    //^ Exception: adding an empty Vecteur and another Vecteur
    //vTest+vDiffSize;
    //^ Exception: adding Vecteurs of different size
    //vTest+vOverflow;
    //^ Exception: overflow

    cout << "vTest - vTest : " << vTest-vTest << endl;
    //vTest-vEmpty;
    //^ Exception: subtracting an empty Vecteur and another Vecteur
    //vTest-vDiffSize;
    //^ Exception: subtracting Vecteurs of different size
    //(vOverflow*(-1))-vTest;
    //^ Exception: overflow

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
    //^ Exception: if the matrice has 0 row, it can't have any columns
    //Matrice<int> negativeRowColumnsMatrice(-2, 3);
    //^ Exception: with negative rows -> bad alloc
    //Matrice<int> rowNegativeColumnsMatrice(2, -3);
    //^ Exception: with negative columns -> erro length

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




    cout << endl << "----- Test of Matrice methods" << endl;

    cout << "Read mTest at row 0 : " << mTest.at(0) << endl;
    //mTest.at(10);
    //^ Exception: read at row 10
    cout << "Read mTest at row 0, column 1 : " << mTest.at(0).at(1) << endl;
    //mTest.at(0).at(10);
    //^ Exception: read at row 0, column 10

    Vecteur<int> mTestRow1{vector<int>{4,5,6}};
    mTest.at(1) = mTestRow1;
    cout << "After writing [4, 5, 6] in mTest at row 1 : " << mTest << endl;
    //mTest.at(10) = mTestRow1;
    //^ Exception: writing [4, 5, 6] in mTest at row 10
    mTest.at(1).at(2) = 7;
    cout << "After writing 7 in mTest at row 1, column 2 : " << mTest << endl;
    //mTest.at(1).at(10) = 7;
    //^ Exception: writing 7 in mTest at row 1, column 10

    cout << "Size of mTest (Nb of rows) : " << mTest.size() << endl;

    mTest.resize(4);
    cout << "After resizing mTest from 2 rows to 3 : " << mTest << endl;
    //vTest.resize(-2);
    //^ Exception: resizing with a negative value
    mTest.resize(4, 4);
    cout << "After resizing mTest from 3 columns to 4 : " << mTest << endl;
    //mTest.resize(3, -2);
    //^ Exception: resizing with a negative value
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
    //^ Exception: can not sum rows of an empty matrice
    //mTest.sommeLigne();
    //^ Exception: can not sum rows of any empty matrice
    //mOverflow.sommeLigne();
    //^ Exception: overflow

    cout << "Somme of each columns in mReguliere : " << mReguliere.sommeColonne() << endl;
    //mEmpty.sommeColonne();
    //^ Exception: can not sum columns of an empty matrice
    //cout << mTest.sommeColonne() << endl;
    //^ Exception: can not sum columns of a not Reguliere matrice
    //mOverflow.sommeColonne();
    //^ Exception: overflow

    cout << "Somme of diagonal left to right in m2x2 : " << m2x2.sommeDiagonaleGD() << endl;
    //mEmpty.sommeDiagonaleGD();
    //^ Exception: can not sum diagonale of an empty matrice
    //mTest.sommeDiagonaleGD();
    //^ Exception: can not sum diagonale of a not carree matrice
    //mOverflow.sommeDiagonaleGD();
    //^ Exception: overflow

    cout << "Somme of diagonal right to left in m2x2 : " << m2x2.sommeDiagonaleDG() << endl;
    //mEmpty.sommeDiagonaleDG();
    //^ Exception: can not sum diagonale of an empty matrice
    //mTest.sommeDiagonaleDG();
    //^ Exception: can not sum diagonale of a not carree matrice
    //mOverflow.sommeDiagonaleDG();
    //^ Exception: overflow
    cout << endl;

    cout << "mReguliere * 2 : " << mReguliere*2 << endl;
    //mEmpty*2;
    //^ Exception: can not multiply an empty Matrice
    //mOverflow*2;
    //^ Exception: overflow
    cout << endl;

    // resizing mTest to test arithmetic operations between Matrices
    mTest.resize(2, 3);
    cout << "Matrice lhs (mTest): " << mTest << endl;
    cout << "Matrice rhs (mReguliere): " << mReguliere << endl;



    cout << "lhs*rhs = " << mTest*mReguliere << endl;
    //mTest*mEmpty;
    //^ Exception : can not multiply a Matrice with an empty one
    //mTest*m1x3;
    //^ Exception: not the same nb of rows
    //mTest*m2x2;
    //^ Exception: not the same nb of elements in rows
    //m2x2*mOverflow;
    //^ Exception: overflow

    cout << "lhs+rhs = " << mTest+mReguliere << endl;
    //mTest+mEmpty;
    //^ Exception : can not multiply a Matrice with an empty one
    //mTest+m1x3;
    //^ Exception: not the same nb of rows
    //mTest+m2x2;
    //^ Exception: not the same nb of elements in rows
    //m2x2+mOverflow;
    //^ Exception: overflow

}

int main() {

    /*
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

    vector<int> test1 {2};
    vector<int> test2 {4};
    Vecteur<int> monVecteur1(test1);
    Vecteur<int> monVecteur2(test2);

    cout << monVecteur1.somme() << endl;
    cout << (monVecteur1 + monVecteur2) << endl;
    cout << (monVecteur1 - monVecteur2) << endl;
    cout << monVecteur1 * 1 << endl;
    cout << monVecteur1 * monVecteur2 << endl;


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



    Matrice<int> matrice1(3,5);
    Vecteur<int> in{vector<int>{1,2,3,4,5}};
    cout << matrice1.size() << endl;
    matrice1.at(2) = in;
    cout << matrice1 << endl;

    matrice1.at(0).at(4) = 20;
    cout << matrice1 << endl;

    matrice1.resize(6);
    cout << matrice1 << endl;

    matrice1.resize(3, 3);
    matrice1.at(0) = Vecteur<int> {vector<int>{1,3,4}};
    matrice1.at(1) = Vecteur<int> {vector<int>{1,5,2}};
    matrice1.at(2) = Vecteur<int> {vector<int>{1,2,3}};
    cout << matrice1 << endl;

    cout << "Matrice vide ? " << boolalpha << matrice1.estVide() << noboolalpha << endl;

    cout << "Matrice carree ? " << boolalpha << matrice1.estCarree() << noboolalpha << endl;

    cout << "Matrice reguliere ? " << boolalpha << matrice1.estReguliere() << noboolalpha << endl;

    cout << matrice1.sommeLigne() << endl;

    cout << matrice1.sommeColonne() << endl;

    cout << matrice1.sommeDiagonaleGD() << endl;

    cout << matrice1.sommeDiagonaleDG() << endl;

    cout << (matrice1 * 3) << endl;
    cout << (matrice1 * matrice1) << endl;
    cout << (matrice1 + matrice1) << endl;

    */

    testVecteur();
    //testMatrice();
    return 0;
}