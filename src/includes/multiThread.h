//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_MULTITHREAD_H
#define FINDPRIMES_MULTITHREAD_MULTITHREAD_H

#include "../bits/stdc++.h"
#include "argInput.h"
#include "utilities.h"

inline auto preSieve(const long long &n,
                     void (*pPreSieveMethod)(const long long &n,
                                             std::vector<long long> &primes)) {
  // 计算sqrt(n)
  long long sqrtN = std::sqrt(n);

  // 向量存储预筛结果
  std::vector<long long> preSievedPrimes;

  // 根据m调用预筛算法
  (*pPreSieveMethod)(sqrtN, preSievedPrimes);

  return std::make_pair(sqrtN, preSievedPrimes);
}

inline std::vector<std::vector<long long>> multiThreadSieve(
    const long long &n, const long long &sqrtN, const int &threads,
    std::vector<long long> preSievedPrimes,
    void (*pMultiMethod)(const long long &lL, const long long &uL,
                         std::vector<long long> &primes,
                         const std::vector<long long> &preSievedPrimes)) {
  // 每个线程筛选的数值范围
  long long perThread = (n - sqrtN) / threads;

  // 向量存储threads个线程
  std::vector<std::thread> vThread;

  // threads个线程的筛选结果
  std::vector<std::vector<long long>> primesVec(threads);

  // 检查预筛结果是否为空
  if (preSievedPrimes.empty())
    throw std::runtime_error("Empty preSievedPrimes!");

  // 启动threads个筛选线程
  for (int i = 0; i < threads; ++i) {

    // 计算每个线程的下限上限
    long long lL = sqrtN + i * perThread + 1;
    long long uL = sqrtN + (i + 1) * perThread;

    // 最后一个线程上限为n
    if (i == threads - 1)
      uL = n;

    // 启动线程,调用sievePrimes筛选素数
    std::thread thr((*pMultiMethod), lL, uL, std::ref(primesVec[i]),
                    std::cref(preSievedPrimes));

    // 将线程加入向量
    vThread.emplace_back(std::move(thr));
  }

  // 等待所有线程结束
  for (auto &thr : vThread)
    if (thr.joinable())
      thr.join();

  return primesVec;
}

inline long long
writeToFileMultiT(const std::vector<long long> &preSievedPrimes,
                  const std::vector<std::vector<long long>> &primesVec,
                  const std::string &file) {
  // 打开输出文件
  std::ofstream outfile(file);

  // 判断打开是否成功
  if (!outfile.is_open())
    throw std::runtime_error("Failed to open file.");

  // 输出预筛结果
  for (long long i : preSievedPrimes)
    outfile << i << " ";

  // 输出筛选结果
  long long totalSize = preSievedPrimes.size();
  for (auto &vec : primesVec) {
    for (long long i : vec)
      outfile << i << " ";
    totalSize += vec.size();
  }

  // 关闭文件
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
