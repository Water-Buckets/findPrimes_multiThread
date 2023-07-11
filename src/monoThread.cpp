//
// Created by ASUS on 2023/7/10.
//

#include "monoThread.h"

void monoThread(const long long &n, const char &m, const std::string &file) {
    std::vector<long long> primes;
    auto start = std::chrono::steady_clock::now();
    switch (m) {
        case 'a':
            std::clog << "Using Trial Division" << std::endl;
            trialDivision(n, primes);
            break;
        case 'b':
            std::clog << "Using Sieve of Eratosthenes" << std::endl;
            eratosthenesSieve(n, primes);
            break;
        case 'c':
            std::clog << "Using Sieve of Euler" << std::endl;
            eulerSieve(n, primes);
            break;
        case 'd':
            std::clog << "Using Sieve of Sundaram" << std::endl;
            sundaramSieve(n, primes);
            break;
        case 'e':
            std::clog << "Using Sieve of Atkin" << std::endl;
            atkinSieve(n, primes);
            break;
        case 'f':
            std::clog << "Using Incremental Sieve" << std::endl;
            incrementalSieve(n, primes);
            break;
        case 'g':
            std::clog << "Using Wheel Sieve" << std::endl;
            wheelSieve(n, primes);
            break;
        default:
            throw std::invalid_argument("Invalid input.");
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long duration = diff.count();
    std::clog << "Found " << primes.size() << " primes in " << double(duration) / 1000000000 << " seconds."
              << std::endl;
    auto startWrite = std::chrono::steady_clock::now();
    std::ofstream outfile(file);
    if (!outfile.is_open()) throw std::runtime_error("Failed to open file.");
    for (auto p: primes) {
        outfile << p << " ";
    }
    outfile.close();
    auto endWrite = std::chrono::steady_clock::now();
    auto diffWrite = std::chrono::duration_cast<std::chrono::nanoseconds>(endWrite - startWrite);
    long long durationWrite = diffWrite.count();
    std::clog << "Time elapsed writing to file: " << double(durationWrite) / 1000000000 << " seconds." << std::endl;
    std::cout << "Total time elapsed: " << double(duration + durationWrite) / 1000000000 << " seconds." << std::endl;
    std::cout << "Done. Check " << file << " for " << primes.size() << " results." << std::endl;
}