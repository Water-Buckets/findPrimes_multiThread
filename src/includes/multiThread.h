//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_MULTITHREAD_H
#define FINDPRIMES_MULTITHREAD_MULTITHREAD_H

#include "utilities.h"
#include <cmath>
#include <fstream>
#include <thread>
#include <vector>

inline auto preSieve(const long long &n,
                     void (*pPreSieveMethod)(const long long &n,
                                             std::vector<long long> &primes)) {
  // calculate sqrt(n)
  long long sqrtN = std::sqrt(n);

  // define preSievedPrimes vector to store pre-sieved primes
  std::vector<long long> preSievedPrimes;

  // call preSieveMethod based on the pointer
  (*pPreSieveMethod)(sqrtN, preSievedPrimes);

  return std::make_pair(sqrtN, preSievedPrimes);
}

inline std::vector<std::vector<long long>> multiThreadSieve(
    const long long &n, const long long &sqrtN, const int &threads,
    std::vector<long long> preSievedPrimes,
    void (*pMultiMethod)(const long long &lL, const long long &uL,
                         std::vector<long long> &primes,
                         const std::vector<long long> &preSievedPrimes)) {
  // range per thread
  long long perThread = (n - sqrtN) / threads;

  // define threads vector to store threads
  std::vector<std::thread> vThread;

  // define primesVec vector to store primes
  std::vector<std::vector<long long>> primesVec(threads);

  // check if preSievedPrimes is empty
  if (preSievedPrimes.empty())
    throw std::runtime_error("Empty preSievedPrimes!");

  // start threads
  for (int i = 0; i < threads; ++i) {

    // calculate lower and upper limit
    long long lL = sqrtN + i * perThread + 1;
    long long uL = sqrtN + (i + 1) * perThread;

    // the upper limit of the last thread should be n
    if (i == threads - 1)
      uL = n;

    // start thread and call pMultiMethod to sieve
    std::thread thr((*pMultiMethod), lL, uL, std::ref(primesVec[i]),
                    std::cref(preSievedPrimes));

    // add thread to vThread
    vThread.emplace_back(std::move(thr));
  }

  // join threads
  for (auto &thr : vThread)
    if (thr.joinable())
      thr.join();

  return primesVec;
}

inline long long
writeToFileMultiT(const std::vector<long long> &preSievedPrimes,
                  const std::vector<std::vector<long long>> &primesVec,
                  const std::string &file) {
  // open file
  std::ofstream outfile(file);

  // check if file is open
  if (!outfile.is_open())
    throw std::runtime_error("Failed to open file.");

  // output preSievedPrimes
  for (long long i : preSievedPrimes)
    outfile << i << " ";

  // output primesVec
  long long totalSize = preSievedPrimes.size();
  for (auto &vec : primesVec) {
    for (long long i : vec)
      outfile << i << " ";
    totalSize += vec.size();
  }

  // close file
  outfile.close();
  return totalSize;
}

void multiThread(
    const int &threads, const long long &n, const std::string &file,
    void (*pMultiMethod)(const long long &lL, const long long &uL,
                         std::vector<long long> &primes,
                         const std::vector<long long> &preSievedPrimes),
    void (*pPreSieveMethod)(const long long &n,
                            std::vector<long long> &primes));

#endif // FINDPRIMES_MULTITHREAD_MULTITHREAD_H
