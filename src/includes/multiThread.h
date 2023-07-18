//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_MULTITHREAD_H
#define FINDPRIMES_MULTITHREAD_MULTITHREAD_H

#include "../bits/stdc++.h"
#include "argInput.h"

void multiThread(
    const int &threads, const long long &n, const std::string &file,
    void (*pMultiMethod)(const long long &lL, const long long &uL,
                         std::vector<long long> &primes,
                         const std::vector<long long> &preSievedPrimes),
    void (*pPreSieveMethod)(const long long &n,
                            std::vector<long long> &primes));

#endif // FINDPRIMES_MULTITHREAD_MULTITHREAD_H
