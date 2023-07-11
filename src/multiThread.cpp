//
// Created by ASUS on 2023/7/7.
//
#include "multiThread.h"
#include "preSieve.h"


void multiThread(const int &threads, const char &m, const long long &n, const std::string &file) {
    if (m == 'e') exit(0);
    auto startPre = std::chrono::steady_clock::now();
    long long sqrtN = std::sqrt(n);
    std::vector<long long> preSievedPrimes;
    preSieve(sqrtN, m, preSievedPrimes);
    auto endPre = std::chrono::steady_clock::now();
    auto diffPre = std::chrono::duration_cast<std::chrono::nanoseconds>(endPre - startPre);
    long long durationPre = diffPre.count();
    std::cout << "Time elapsed pre-sieveing:" << double(durationPre) / 1000000000 << " seconds." << std::endl;
    auto start = std::chrono::steady_clock::now();
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
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long duration = diff.count();
    std::cout << "Time elapsed sieveing:" << double(duration) / 1000000000 << " seconds." << std::endl;
    auto startWrite = std::chrono::steady_clock::now();
    std::ofstream outfile(file);
    if (!outfile.is_open()) throw std::runtime_error("Failed to open file.");
    for (long long i: preSievedPrimes) {
        outfile << i << " ";
    }
    long long totalSize = preSievedPrimes.size();
    for (auto &vec: primesVec) {
        for (long long i: vec) {
            outfile << i << " ";
        }
        totalSize += vec.size();
    }
    outfile.close();
    auto endWrite = std::chrono::steady_clock::now();
    auto diffWrite = std::chrono::duration_cast<std::chrono::nanoseconds>(endWrite - startWrite);
    long long durationWrite = diffWrite.count();
    std::clog << "Time elapsed writing to file: " << double(durationWrite) / 1000000000 << " seconds." << std::endl;
    std::cout << "Total time elapsed: " << double(durationPre + duration + durationWrite) / 1000000000 << " seconds."
              << std::endl;
    std::cout << "Done. Check " << file << " for " << totalSize << " results." << std::endl;
}