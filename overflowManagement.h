//
// Created by loic on 4/0/19.
//

#ifndef OVERFLOWMANAGEMENT_H
#define OVERFLOWMANAGEMENT_H

#include "Exception_overflow_error.h"

template <typename T>
bool isAnAddOverflow(const T& lhs, const T& rhs) {
    T defaultVal = T();
    return ((lhs >= defaultVal) and (rhs >= defaultVal) and ((lhs + rhs) < defaultVal))
            or
            ((lhs < defaultVal) and (rhs < defaultVal) and ((lhs + rhs) >= defaultVal));
}

template <typename T>
bool isASubOverflow(const T& lhs, const T& rhs) {
    T defaultVal = T();
    return ((lhs >= defaultVal) and (rhs < defaultVal) and ((lhs - rhs) < defaultVal))
            or
            ((lhs < defaultVal) and (rhs >= defaultVal) and ((lhs - rhs) >= defaultVal));
}

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
