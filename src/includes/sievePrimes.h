//
// Created by ASUS on 2023/7/9.
//

#ifndef FINDPRIMES_MULTITHREAD_SIEVEPRIMES_H
#define FINDPRIMES_MULTITHREAD_SIEVEPRIMES_H

#include "../bits/stdc++.h"
#include "segSieveMethods.h"

void sievePrimes(const long long lL, const long long uL, const char &m, std::vector<long long> &primes,
                 const std::vector<long long> &preSievedPrimes);

#endif // FINDPRIMES_MULTITHREAD_SIEVEPRIMES_H
