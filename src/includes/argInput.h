//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_ARGINPUT_H
#define FINDPRIMES_MULTITHREAD_ARGINPUT_H

#include "../bits/stdc++.h"
#include "monoThread.h"
#include "multiThread.h"
#include "preSieveMethods.h"
#include "sieveMethods.h"

inline bool isNumeric(const std::string &str) {
    for (char c: str) if (!std::isdigit(c)) return false;
    return true;
}

inline auto switchMonoMethods(const char &m) -> void (*)(const long long &n, std::vector<long long> &primes) {
    switch (m) {
        case 'a':
            return trialDivision;
        case 'b':
            return eratosthenesSieve;
        case 'c':
            return eulerSieve;
        case 'd':
            return sundaramSieve;
        case 'e':
            return atkinSieve;
        case 'f':
            return incrementalSieve;
        case 'g':
            return wheelSieve;
        default:
            throw std::invalid_argument("Invalid argument.");
    }
}

inline auto
switchMultiMethods(const char &m) -> void (*)(const long long &lL, const long long &uL, std::vector<long long> &primes,
                                              const std::vector<long long> &preSievedPrimes) {
    switch (m) {
        case 'a':
            return segTrialDivision;
        case 'b':
            return segEratosthenesSieve;
        case 'c':
            return segEulerSieve;
        case 'd':
            return segSundaramSieve;
        case 'e':
            throw std::runtime_error("What?!");
        case 'f':
            return segIncrementalSieve;
        case 'g':
            throw std::runtime_error("What?!");
        default:
            throw std::invalid_argument("Invalid argument.");
    }
}

void argInput(char *argv[]);

#endif // FINDPRIMES_MULTITHREAD_ARGINPUT_H
