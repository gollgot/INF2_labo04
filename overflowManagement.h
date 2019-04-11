//
// Created by loic on 4/0/19.
//

#ifndef OVERFLOWMANAGEMENT_H
#define OVERFLOWMANAGEMENT_H

#include "Exception_overflow_error.h"

/**
 * @brief  Check if the sum between the parameters is an overflow
 * @tparam T Generic type
 * @param lhs The left value
 * @param rhs The right value
 *
 * @return True if there is an overflow, false otherwise
 */
template <typename T>
bool isAnAddOverflow(const T& lhs, const T& rhs) {
    T defaultVal = T();
    return ((lhs >= defaultVal) and (rhs >= defaultVal) and ((lhs + rhs) < defaultVal))
            or
            ((lhs < defaultVal) and (rhs < defaultVal) and ((lhs + rhs) >= defaultVal));
}

/**
 * @brief  Check if the subtraction between the parameters is an overflow
 * @tparam T Generic type
 * @param lhs The left value
 * @param rhs The right value
 *
 * @return True if there is an overflow, false otherwise
 */
template <typename T>
bool isASubOverflow(const T& lhs, const T& rhs) {
    T defaultVal = T();
    return ((lhs >= defaultVal) and (rhs < defaultVal) and ((lhs - rhs) < defaultVal))
            or
            ((lhs < defaultVal) and (rhs >= defaultVal) and ((lhs - rhs) >= defaultVal));
}

/**
 * @brief  Check if the multiplication between the parameters is an overflow
 * @tparam T Generic type
 * @param lhs The left value
 * @param rhs The right value
 *
 * @return True if there is an overflow, false otherwise
 */
template <typename T>
bool isAMultiplyOverflow(const T& lhs, const T& rhs){
    T intermediateResult = lhs;
    T begin = T();
    for(T i = ++begin; i < rhs; ++i) {
        if(isAnAddOverflow(intermediateResult, lhs)) {
            return true;
        }
        intermediateResult += lhs;
    }

    return false;
}

#endif //OVERFLOWMANAGEMENT_H
