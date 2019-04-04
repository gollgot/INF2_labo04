//
// Created by loic on 4/2/19.
//

#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

#include <iostream>
#include <vector>

template <typename T>
Vecteur<T>::Vecteur(size_t n) noexcept : data(std::vector<T>(n)) {}

template <typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vector) noexcept : data(vector) {}

#endif //VECTEURIMPL_H
