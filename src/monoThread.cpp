//
// Created by ASUS on 2023/7/10.
//

#include "includes/monoThread.h"
#include "utilities.h"

// 单线程筛选素数
void monoThread(const long long &n, const std::string &file,
                void (*pMonoMethod)(const long long &n,
                                    std::vector<long long> &primes)) {
  // 检查函数指针是否为空
  if (pMonoMethod == nullptr)
    throw std::runtime_error("Null pointer exception.");

  auto results =
      timer(monoThreadSieve, "Time elapsed sieveing: ", n, pMonoMethod);
  auto primes = results.first;
  auto duration = results.second;

  auto writeResults =
      timer(writeToFile, "Time elapsed writing to file: ", primes, file);
  if (writeResults.first != 0)
    throw std::runtime_error("Error writing to file");

  auto durationWrite = writeResults.second;

  // 输出总用时
  std::cout << "Total time elapsed: "
            << double(duration + durationWrite) / 1000000000 << " seconds."
            << std::endl;

  // 提示输出文件和结果数量
  std::cout << "Done. Check " << file << " for " << primes.size() << " results."
            << std::endl;
}