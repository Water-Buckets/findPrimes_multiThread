//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_ARGINPUT_H
#define FINDPRIMES_MULTITHREAD_ARGINPUT_H

#include "bits/stdc++.h"
#include "multiThread.h"
#include "monoThread.h"

inline bool isNumeric(const std::string &str) {
    for (char c: str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

void argInput(char *argv[]);

#endif //FINDPRIMES_MULTITHREAD_ARGINPUT_H
