//
// Created by loic on 4/2/19.
//

#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <vector>

// We have to declare our Vecteur class to be able to use it as a parameter
template<typename T>
class Vecteur;

/**
 * @brief Display a Vecteur object
 * @tparam T Generic type
 * @param os The output stream
 * @param rhs The right value
 *
 * @return The current output stream reference to be able to chain them
 */
template <typename T>
std::ostream& operator<< (std::ostream& os, const Vecteur<T>& rhs) noexcept {
    os << "[";
    for(std::size_t i = 0; i < rhs.size(); ++i) {
        if(i > 0) {
            os << ", ";
        }
        os << rhs.at(i);
    }
    os << "]";

    return os;
}


template <typename T>
class Vecteur {

public:
    /**
     * @brief Empty constructor to create an empty Vecteur (size of 0)
     */
    Vecteur();

    /**
     * @brief Constructor to create a Vecteur with size of n
     * @param n The Vecteur size
     */
    Vecteur(size_t n);

    /**
     * @brief Consructor to create a Vecteur from a specific vector
     * @param vector The Vecteur data
     */
    Vecteur(const std::vector<T>& vector);

    /**
     * @brief Select an element at a specific position
     * @param n Position of an element in the Vecteur. Notice that the first element has a position of 0 (not 1).
     * @throws Exception_out_of_range is throw if n is greater than, or equal to, the Vecteur size
     *
     * @return The element at the specified position in the Vecteur.
     */
    T at(size_t n) const;

    /**
     * @brief Select an element at a specific position
     * @param n Position of an element in the Vecteur. Notice that the first element has a position of 0 (not 1).
     * @throws Exception_out_of_range is thrown if n is greater than, or equal to, the Vecteur size
     *
     * @return A reference to the element at the specified position in the container. (can be use to write in)
     */
    T& at(size_t n);

    /**
     * @brief Returns the number of elements in the Vecteur.
     * @return The number of elements in the Vecteur.
     */
    size_t size() const noexcept;

    /**
     * @brief Resizes the Vecteur so that it contains "size" elements.
     * @param size New Vecteur size, expressed in number of elements.
     * @throws Exception_length_error is thrown if "size" is greater than the maximum number of elements the Vecteur can hold
     * @throws Exception_bad_alloc is thrown if this is impossible to allocate the asked memory
     *
     * @details If "size" is smaller than the current Vecteur size, the content is reduced to its first n elements,
     *          removing those beyond (and destroying them). If "size" is greater than the current Vecteur size,
     *          the content is expanded by inserting at the end as many elements as needed to reach a size of "size".
     *          If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
     *          If n is also greater than the current container capacity, an automatic reallocation of the allocated
     *          storage space takes place.
     */
    void resize(size_t size);

    /**
     * @brief Sum all the elements contains in the Vecteur
     * @throws Exception_length_error is thrown if we try to sum an empty Vecteur
     * @throws Exception_overflow_error is thrown if the addition return an overflow
     *
     * @return The sum of all elements contains in the Vecteur
     */
    T somme() const;

    /**
     * @brief Display a Vecteur object
     * @param os The output stream
     * @param rhs The right Vecteur
     */
    friend std::ostream& operator<< <T>(std::ostream& os, const Vecteur<T>& rhs) noexcept;


    /**
     * @brief Multiply each element in the Vecteur by a value
     * @param val The value we want to multiply with all our Vecteur's elements
     * @throws Exception_length_error is thrown if we try to multiply an empty Vecteur
     * @throws Exception_overflow_error is thrown if the multiplication return an overflow
     *
     * @return A new Vecteur contains the result of the multiplication
     */
    Vecteur<T> operator*(const T& val);

    /**
     * @brief Multiply two Vecteurs value by value
     * @param rhs The right Vecteur
     * @throws Exception_length_error is thrown if we try to multiply an empty Vecteur with an other Vecteur
     * @throws Exception_invalid_argument is thrown if we try to multiply Vecteurs of different size.
     * @throws Exception_overflow_error is thrown if the multiplication return an overflow
     *
     * @return A new vecteur contains the result of the multiplication
     */
    Vecteur<T> operator*(const Vecteur<T>& rhs);

    /**
     * @brief  Addition between two Vecteur, value by value
     * @param rhs The right Vecteur
     * @throws Exception_length_error is thrown if we try to sum an empty Vecteur with an other Vecteur
     * @throws Exception_invalid_argument is thrown if we try to sum Vecteurs of different size.
     * @throws Exception_overflow_error is thrown if the sum return an overflow
     *
     * @return A new Vecteur contains the result of the addition
     */
    Vecteur<T> operator+(const Vecteur<T>& rhs);

    /**
     * @brief Subtraction between two vecteur, value by value
     * @param rhs The right Valeur
     * @throws Exception_length_error is thrown if we try to subtract an empty Vecteur with an other Vecteur
     * @throws Exception_invalid_argument is thrown if we try to subtract Vecteurs of different size.
     * @throws Exception_overflow_error is thrown if the subtraction return an overflow
     *
     * @return A new Vecteur contains the result of the subtraction
     */
    Vecteur<T> operator-(const Vecteur<T>& rhs);


private:
    std::vector<T> data;
};

#include "VecteurImpl.h"

#endif //VECTEUR_H
