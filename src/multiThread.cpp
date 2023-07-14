//
// Created by ASUS on 2023/7/7.
//
#include "includes/multiThread.h"
#include "includes/preSieve.h"

void multiThread(const int &threads, const char &m, const long long &n,
                 const std::string &file) {

    auto startPre = std::chrono::steady_clock::now();

    long long sqrtN = std::sqrt(n);
#ifndef NDEBUG
    std::cerr << __func__ << ": " << sqrtN << std::endl;
#endif
    std::vector<long long> preSievedPrimes;
    preSieve(sqrtN, m, preSievedPrimes);
#ifndef NDEBUG
    std::cerr << __func__ << ": ";
    for (auto &i: preSievedPrimes) {
        std::cerr << i << " ";
    }
    std::cerr << std::endl;
#endif

    auto endPre = std::chrono::steady_clock::now();
    auto diffPre = std::chrono::duration_cast<std::chrono::nanoseconds>(endPre - startPre);
    long long durationPre = diffPre.count();
    std::cout << "Time elapsed pre-sieveing:" << double(durationPre) / 1000000000 << " seconds." << std::endl;

    auto start = std::chrono::steady_clock::now();

    std::vector<std::thread> vThread;
    long long perThread = (n - sqrtN) / threads;
    std::vector<std::vector<long long>> primesVec(threads);
    if (preSievedPrimes.empty()) throw std::runtime_error("Empty preSievedPrimes!");
#ifndef NDEBUG
    std::cerr << __func__ << ": " << "perThread: " << perThread << std::endl;
#endif
    for (int i = 0; i < threads; ++i) {
        long long lL = sqrtN + i * perThread + 1;
        long long uL = sqrtN + (i + 1) * perThread;
        if (i == threads - 1) uL = n;
#ifndef NDEBUG
        std::cerr << __func__ << ": " << "thread " << i << ": " << lL << " " << uL << std::endl;
#endif
        std::thread thr(sievePrimes, lL, uL, std::cref(m),
                        std::ref(primesVec[i]), std::cref(preSievedPrimes));
        vThread.emplace_back(std::move(thr));
    }

    for (auto &thr: vThread) if (thr.joinable()) thr.join();

    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long duration = diff.count();
    std::cout << "Time elapsed sieveing:" << double(duration) / 1000000000 << " seconds." << std::endl;

#ifndef NDEBUG
    std::cerr << __func__ << ": " << "size of primesVec: " << primesVec.size() << std::endl;
    for (auto &vec: primesVec) {
        std::cerr << __func__ << ": " << "size of vec: " << vec.size() << std::endl;
        for (auto &i: vec) {
            std::cerr << i << " ";
        }
        std::cerr << std::endl;
    }
#endif

    auto startWrite = std::chrono::steady_clock::now();

    std::ofstream outfile(file);
    if (!outfile.is_open()) throw std::runtime_error("Failed to open file.");
    for (long long i: preSievedPrimes) outfile << i << " ";
    long long totalSize = preSievedPrimes.size();
    for (auto &vec: primesVec) {
        for (long long i: vec) outfile << i << " ";
        totalSize += vec.size();
    }
    outfile.close();

    auto endWrite = std::chrono::steady_clock::now();
    auto diffWrite = std::chrono::duration_cast<std::chrono::nanoseconds>(endWrite - startWrite);
    long long durationWrite = diffWrite.count();
    std::cout << "Time elapsed writing to file: " << double(durationWrite) / 1000000000 << " seconds." << std::endl;
    std::cout << "Total time elapsed: " << double(durationPre + duration + durationWrite) / 1000000000 << " seconds."
              << std::endl;
    std::cout << "Done. Check " << file << " for " << totalSize << " results." << std::endl;
}