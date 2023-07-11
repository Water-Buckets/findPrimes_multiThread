//
// Created by ASUS on 2023/7/9.
//

#ifndef FINDPRIMES_MULTITHREAD_UTILITIES_H
#define FINDPRIMES_MULTITHREAD_UTILITIES_H

#include "bits/stdc++.h"

inline bool isNumeric(const std::string &str) {
    for (char c: str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}


#endif //FINDPRIMES_MULTITHREAD_UTILITIES_H
