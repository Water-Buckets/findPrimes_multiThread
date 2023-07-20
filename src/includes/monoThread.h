//
// Created by ASUS on 2023/7/10.
//

#ifndef FINDPRIMES_MULTITHREAD_MONOTHREAD_H
#define FINDPRIMES_MULTITHREAD_MONOTHREAD_H

#include "utilities.h"
#include <fstream>
#include <vector>

inline std::vector<long long> monoThreadSieve(
    const long long &n,
    void (*pMonoMethod)(const long long &n, std::vector<long long> &primes)) {
  // define primes vector to store primes
  std::vector<long long> primes;
  // call pMonoMethod based on the pointer
  (*pMonoMethod)(n, primes);

  return primes;
}

inline int writeToFileMonoT(std::vector<long long> primes,
                            const std::string &file) {
  // open file
  std::ofstream outfile(file);

  // check if file is open
  if (!outfile.is_open()) {
    throw std::runtime_error("Failed to open file.");
  }

  // write to file
  for (auto p : primes) {
    outfile << p << " ";
  }

  // close file
  outfile.close();
  return 0;
}

void monoThread(const long long &n, const std::string &file,
                void (*pMonoMethod)(const long long &n,
                                    std::vector<long long> &primes));

#endif // FINDPRIMES_MULTITHREAD_MONOTHREAD_H
