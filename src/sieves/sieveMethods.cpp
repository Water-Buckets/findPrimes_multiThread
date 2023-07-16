//
// Created by ASUS on 2023/7/11.
//

#include "../includes/sieveMethods.h"

void trialDivision(const long long &lL, const long long &uL, std::vector<long long> &primes,
                   const std::vector<long long> &preSievedPrimes) {
    for (long long i = std::max(2LL, lL); i <= uL; ++i) {
        bool isPrime = true;
        for (const long long &p: preSievedPrimes) {
            if (p * p > i) break;
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(i);
    }
}

void eratosthenesSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                       const std::vector<long long> &preSievedPrimes) {
    std::vector<bool> isPrime(uL - lL + 1, true);
    for (const long long &p: preSievedPrimes)
        for (long long i = std::max(p * p, (lL + p - 1) / p * p); i <= uL; i += p)isPrime[i - lL] = false;
    for (long long i = (lL < 2) ? 2 - lL : 0; i <= uL - lL; ++i) if (isPrime[i]) primes.push_back(i + lL);
}

void eulerSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                const std::vector<long long> &preSievedPrimes) {
    std::vector<bool> isPrime(uL - lL + 1, true);
    for (const long long &p: preSievedPrimes)
        for (long long i = std::max(p * p, (lL + p - 1) / p * p); i <= uL; i += p)isPrime[i - lL] = false;
    for (long long i = (lL < 2) ? 2 - lL : 0; i <= uL - lL; ++i) {
        if (isPrime[i]) {
            primes.push_back(i + lL);
            for (long long j = (i + lL) * (i + lL); j <= uL; j += i + lL) isPrime[j - lL] = false;
        }
    }
}

void sundaramSieve(const long long &lL, const long long &uL, std::vector<long long> &primes) {
    const long long &nNew = (uL - 1) / 2;
    std::vector<bool> isPrime(nNew + 1, true);
    for (long long i = 1; i <= nNew; ++i)
        for (long long j = i; (i + j + 2 * i * j) <= nNew; ++j) isPrime[i + j + 2 * i * j] = false;
    for (long long i = std::max(lL / 2, 1LL); i <= nNew; ++i) if (isPrime[i]) primes.push_back(2 * i + 1);
}

void incrementalSieve(const long long &lL, const long long &uL, std::vector<long long> &primes,
                      const std::vector<long long> &preSievedPrimes) {
    std::vector<bool> isPrime(uL - lL + 1, true);
    for (const long long &p: preSievedPrimes)
        for (long long i = std::max(p * p, (lL + p - 1) / p * p); i <= uL; i += p)isPrime[i - lL] = false;
    for (long long i = (lL < 2) ? 2 - lL : 0; i <= uL - lL; ++i) {
        if (isPrime[i]) {
            primes.push_back(i + lL);
            for (long long j = (i + lL) * (i + lL); j <= uL; j += i + lL) {
                isPrime[j - lL] = false;
            }
        }
    }
}