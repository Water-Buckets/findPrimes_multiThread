//
// Created by ASUS on 2023/7/10.
//

#ifndef FINDPRIMES_MULTITHREAD_MONOTHREAD_H
#define FINDPRIMES_MULTITHREAD_MONOTHREAD_H

#include "../bits/stdc++.h"
#include "sieveMethods.h"

inline std::vector<long long> monoThreadSieve(
    const long long &n,
    void (*pMonoMethod)(const long long &n, std::vector<long long> &primes)) {
  // 定义primes向量存储筛选结果
  std::vector<long long> primes;
  // 调用筛选方法
  (*pMonoMethod)(n, primes);

  return primes;
}

inline int writeToFileMonoT(std::vector<long long> primes,
                            const std::string &file) {
  // 打开输出文件
  std::ofstream outfile(file);

  // 检查文件打开是否成功
  if (!outfile.is_open()) {
    throw std::runtime_error("Failed to open file.");
  }

  // 将primes中的结果写入文件
  for (auto p : primes) {
    outfile << p << " ";
  }

  // 关闭文件
  outfile.close();
  return 0;
}

void monoThread(const long long &n, const std::string &file,
                void (*pMonoMethod)(const long long &n,
                                    std::vector<long long> &primes));

#endif // FINDPRIMES_MULTITHREAD_MONOTHREAD_H
