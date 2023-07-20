//
// Created by ASUS on 2023/7/7.
//
#include "includes/multiThread.h"

// 多线程筛选素数
void multiThread(
    const int &threads, const long long &n, const std::string &file,
    void (*pMultiMethod)(const long long &lL, const long long &uL,
                         std::vector<long long> &primes,
                         const std::vector<long long> &preSievedPrimes),
    void (*pPreSieveMethod)(const long long &n,
                            std::vector<long long> &primes)) {
  // 检查函数指针是否为空
  if (pMultiMethod == nullptr || pPreSieveMethod == nullptr)
    throw std::runtime_error("Null pointer exception.");

  auto preSieveResults =
      timer(preSieve, "Time elapsed pre-sieveing: ", n, pPreSieveMethod);

  long long sqrtN = preSieveResults.first.first;
  auto preSievedPrimes = preSieveResults.first.second;
  auto durationPre = preSieveResults.second;

  auto sieveResults = timer(multiThreadSieve, "Time elapsed sieveing: ", n,
                            sqrtN, threads, preSievedPrimes, pMultiMethod);

  auto primesVec = sieveResults.first;
  auto duration = sieveResults.second;

  auto writeResults =
      timer(writeToFileMultiT,
            "Time elapsed writing to file: ", preSievedPrimes, primesVec, file);
  auto totalSize = writeResults.first;
  auto durationWrite = writeResults.second;

  // 输出总时间
  std::cout << "Total time elapsed: "
            << double(durationPre + duration + durationWrite) / 1000000000
            << " seconds." << std::endl;

  // 提示输出结果数量
  std::cout << "Done. Check " << file << " for " << totalSize << " results."
            << std::endl;
}