//
// Created by ASUS on 2023/7/9.
//

#include "includes/sievePrimes.h"

void sievePrimes(const long long lL, const long long uL, const char &m, std::vector<long long> &primes,
                 const std::vector<long long> &preSievedPrimes) {
    switch (m) {
        case 'a':
            trialDivision(lL, uL, primes, preSievedPrimes);
            break;
        case 'b':
            eratosthenesSieve(lL, uL, primes, preSievedPrimes);
            break;
        case 'c':
            eulerSieve(lL, uL, primes, preSievedPrimes);
            break;
        case 'd':
            sundaramSieve(lL, uL, primes);
            break;
        case 'e':
            throw std::runtime_error("What the FUCK?!");
        case 'f':
            incrementalSieve(lL, uL, primes, preSievedPrimes);
            break;
        case 'g':
            throw std::runtime_error("What the FUCK?!");
    }
}
