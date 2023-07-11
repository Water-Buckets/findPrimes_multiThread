//
// Created by ASUS on 2023/7/10.
//

#include "preSieve.h"

void preSieve(const long long &uL, const char &m, std::vector<long long> &primes) {
    switch (m) {
        case 'a':
            trialDivision(uL, primes);
            break;
        case 'b':
            eratosthenesSieve(uL, primes);
            break;
        case 'c':
            eulerSieve(uL, primes);
            break;
        case 'd':
            sundaramSieve(uL, primes);
            break;
        case 'e':
            atkinSieve(uL, primes);
            break;
        case 'f':
            incrementalSieve(uL, primes);
            break;
        case 'g':
            wheelSieve(uL, primes);
            break;
        default:
            throw std::invalid_argument("Invalid input.");
    }
}