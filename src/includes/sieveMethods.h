//
// Created by ASUS on 2023/7/11.
//

#ifndef FINDPRIMES_MULTITHREAD_SIEVEMETHODS_H
#define FINDPRIMES_MULTITHREAD_SIEVEMETHODS_H

#include "../bits/stdc++.h"

void (*trialDivision)(const long long &lL, const long long &uL, std::vector<long long> &primes,
                      const std::vector<long long> &preSievedPrimes);

void eratosthenesSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                       const std::vector<long long> &preSievedPrimes);

void eulerSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                const std::vector<long long> &preSievedPrimes);

void sundaramSieve(const long long &lL, const long long &uL, std::vector<long long> &primes);

void atkinSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                const std::vector<long long> &preSievedPrimes); //unused due tothe complexity of the Atkin Sieve algorithm

void incrementalSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                      const std::vector<long long> &preSievedPrimes);

void wheelSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                const std::vector<long long> &preSievedPrimes); //unused due to the complexity of the Wheel Sieve algorithm


#endif //FINDPRIMES_MULTITHREAD_SIEVEMETHODS_H
