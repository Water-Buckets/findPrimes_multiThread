//
// Created by ASUS on 2023/7/7.
//
#include "multiThread.h"
#include "preSieve.h"


void multiThread(const int &threads, const char &m, const long long &n, const std::string &file) {
    long long sqrtN = std::sqrt(n);
    std::vector<long long> preSievedPrimes;
    preSieve(sqrtN, m, preSievedPrimes);
    std::vector<long long> primes;
    primes.insert(primes.end(), preSievedPrimes.begin(), preSievedPrimes.end());
    std::vector<std::thread> vthread;
    long long perThread = (n - sqrtN) / threads;
    std::vector<std::vector<long long>> primesVec(threads);
    if (preSievedPrimes.empty()) throw std::runtime_error("Empty preSievedPrimes!");
    for (int i = 0; i < threads; ++i) {
        long long lL = sqrtN + i * perThread + 1;
        long long uL = sqrtN + (i + 1) * perThread;
        if (i == threads - 1) uL = n;
        std::thread thr(sievePrimes, std::cref(lL), std::cref(uL), std::cref(m), std::ref(primesVec[i]),
                        std::cref(preSievedPrimes));
        vthread.emplace_back(std::move(thr));
    }
    for (auto &thr: vthread) {
        if (thr.joinable()) thr.join();
    }
    std::ofstream outfile(file);
    if (!outfile.is_open()) throw std::runtime_error("Failed to open file.");
    for (long long i: preSievedPrimes) {
        outfile << i << " ";
    }
    for (auto &vec: primesVec) {
        for (long long i: vec) {
            outfile << i << " ";
        }
    }
    outfile.close();
}