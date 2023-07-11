//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_MULTITHREAD_H
#define FINDPRIMES_MULTITHREAD_MULTITHREAD_H

#include "argInput.h"
#include "bits/stdc++.h"
#include "sievePrimes.h"

void multiThread(const int &threads, const char &m, const long long &n,
                 const std::string &file);

#endif // FINDPRIMES_MULTITHREAD_MULTITHREAD_H
