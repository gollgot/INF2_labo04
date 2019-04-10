//
// Created by loic on 4/10/19.
//

#ifndef OVERFLOWMANAGEMENT_H
#define OVERFLOWMANAGEMENT_H

#include "Exception_overflow_error.h"

template <typename T>
bool isAnAddOverflow(const T& lhs, const T& rhs) {
    return ((lhs >= 0) and (rhs >= 0) and ((lhs + rhs) < 0)) or ((lhs < 0) and (rhs < 0) and ((lhs + rhs) >= 0));
}

template <typename T>
bool isASubOverflow(const T& lhs, const T& rhs) {
    return ((lhs >= 0) and (rhs < 0) and ((lhs - rhs) < 0)) or ((lhs < 0) and (rhs >= 0) and ((lhs - rhs) >= 0));
}

template <typename T>
bool isAMultiplyOverflow(const T& lhs, const T& rhs){
    T intermediateResult = lhs;
    for(T i = 1; i < rhs; ++i) {
        if(isAnAddOverflow(intermediateResult, lhs)) {
            return true;
        }
        intermediateResult += lhs;
    }

    return false;
}

#endif //OVERFLOWMANAGEMENT_H
