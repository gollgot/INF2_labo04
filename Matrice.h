/*
-----------------------------------------------------------------------------------
Laboratoire : Labo04 - Exceptions
Fichier     : Matrice.h
Auteur(s)   : Loic Dessaules, Rosalie Chhen
Date        : 11.04.2019

But         : Contient toutes les déclarations attributs, constructeurs de la classe Matrice

Remarque(s) : -

Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include "Vecteur.h"

template <typename T>
class Matrice;

/**
 * @brief Display a Matrice object
 * @tparam T Generic type
 * @param os The output stream
 * @param rhs The right value
 *
 * @return The current output stream reference to be able to chain them
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrice<T>& rhs){
    os << "[";
    for(size_t row = 0; row < rhs.size(); ++row) {
        os << rhs.at(row);
    }
    os << "]";

    return os;
}

template <typename T>
class Matrice {

public:
    /**
     * @brief Empty constructor to create an empty Matrice (size of 0)
     */
    Matrice<T>();

    /**
     * @brief Constructor to create a Matrice of n rows
     * @param rows The number of rows we want
     * @throws Exception_length_error Is thrown if the row size is greater than the max elements a Vecteur can contains
     * @throws Exception_bad_alloc Is thrown if this is impossible to allocate the asked memory
     */
    Matrice(size_t rows);

    /**
     * @brief Consructor to create a Matrice of x rows and y columns
     * @param rows The number of rows we want
     * @param columns The number of columns we want
     * @throws Exception_invalid_argument Is thrown if rows size is 0 and the columns size is more than 0
     * @throws Exception_length_error Is thrown if the column size is greater than the max elements a Vecteur can contains
     * @throws Exception_bad_alloc Is thrown if this is impossible to allocate the asked memory
     */
    Matrice<T>(size_t rows, size_t columns);

    /**
     * @brief Select an element at a specific position
     * @param n Position of an element in the Matrice. Notice that the first element has a position of 0 (not 1).
     * @throws Exception_out_of_range is throw if n is greater than, or equal to, the number of rows
     *
     * @return The element at the specified position in the Matrice. (a Vecteur object in this case)
     */
    Vecteur<T> at(size_t n) const;

    /**
     * @brief Select an element at a specific position
     * @param n Position of an element in the Matrice. Notice that the first element has a position of 0 (not 1).
     * @throws Exception_out_of_range is throw if n is greater than, or equal to, the number of rows
     *
     * @return A reference to the element at the specified position in the Matrice. (a Vecteur object in this case)
     */
    Vecteur<T>& at(size_t n);

    /**
     * @brief Return the number of rows in the Matrice
     *
     * @return The number of rows in the Matrice
     */
    size_t size() const noexcept;

    /**
     * @brief Resize the Matrice to contains l rows
     * @param l New number of rows in the Matrice
     * @throws length_error is thrown if "l" is greater than the maximum number of row the Matrice can hold
     * @throws Exception_bad_alloc is thrown if this is impossible to allocate the asked memory
     */
    void resize(size_t l);

    /**
     * @brief Resize the Matrice with a new nb of rows and columns
     * @param l New number of rows in the Matrice
     * @param c New number of columns in the Matrice
     * @throws Exception_invalid_argument Is thrown if we have 0 row and more than 0 columns
     * @throws length_error is thrown if "l" or "c" is greater than the maximum number of row or column the Matrice can hold
     * @throws Exception_bad_alloc is thrown if this is impossible to allocate the asked memory
     */
    void resize(size_t l, size_t c);

    /**
     * @brief Check if the Matrice is empty
     * @return True if the Matrice is empty, false otherwise
     */
    bool estVide() const noexcept;

    /**
     * @brief Check if the Matrice is square
     * @return True if this is a swuare Matrice, false otherwise
     */
    bool estCarree() const noexcept;

    /**
     * @brief Check if the Matrice is regular
     * @return True if the Matrice is regular, false otherwise
     */
    bool estReguliere() const noexcept;

    /**
     * @brief Sum all rows of the Matrice
     * @throws Exception_length_error is thrown if we try to sum an empty row
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return A Vecteur object contains the sum of each rows of the Matrice
     */
    Vecteur<T> sommeLigne() const;

    /**
     * @brief Sum all columns of the Matrice
     * @throws Exception_length_error is thrown if we try to sum an empty column
     * @throws Exception_length_error is thrown if we try to sum an irregular Matrice
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return A Vecteur contains the sum of each columns of the Matrice
     */
    Vecteur<T> sommeColonne() const;

    /**
     * @brief Calcul the Diagonal Left to Right of the Matrice
     * @throws Exception_length_error is thrown if we try to calculate the diagonaleGD of an empty Matrice
     * @throws Exception_length_error is thrown if we try to calculate the diagonaleGD of a no square Matrice
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return The sum of the diagonal Left to Right of the Matrice
     */
    T sommeDiagonaleGD() const;

    /**
     * @brief Calcul the Diagonal right to left of the Matrice
     * @throws Exception_length_error is thrown if we try to calculate the diagonaleDG of an empty Matrice
     * @throws Exception_length_error is thrown if we try to calculate the diagonaleDG of a no square Matrice
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return The sum of the diagonal right to left of the Matrice
     */
    T sommeDiagonaleDG() const;

    /**
     * @brief Multiply each element in the Matrice by a specific value
     * @param valeur The value we want to multiply with the Matrice
     * @throws Exception_length_error is thrown if we try to multiply an empty Matrice with a value
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return A new Matrice contains the result of the multiplication
     */
    Matrice<T> operator*(const T& valeur) const;

    /**
     * @brief Multiply the two Matrice, value by value (Hadamard product)
     * @param rhs The right Matrice
     * @throws Exception_length_error is thrown if we try to multiply an empty Matrice
     * @throws Exception_invalid_argument is thrown if both Matrice don't have same nb of rows and columns
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return A new Matrice contains the result of the multiplication
     */
    Matrice<T> operator*(const Matrice<T>& rhs) const;

    /**
     * @brief Sum two Matrice, value by value
     * @param rhs The right Matrice
     * @throws Exception_length_error is thrown if we try to sum an empty Matrice
     * @throws Exception_invalid_argument is thrown if both Matrice don't have same nb of rows and columns
     * @throws Exception_overflow_error is thrown if an overflow has been detected in the computed result
     *
     * @return A new Matrice contains the result of the sum
     */
    Matrice<T> operator+(const Matrice<T>& rhs) const;

    /**
     * @brief Display a Matrice object
     * @param os The output stream
     * @param rhs The right Matrice
     */
    friend std::ostream& operator<< <T>(std::ostream& os, const Matrice<T>& rhs);

private:
    Vecteur<Vecteur<T>> buffer;
};

#include "MatriceImpl.h"

#endif //MATRICE_H
