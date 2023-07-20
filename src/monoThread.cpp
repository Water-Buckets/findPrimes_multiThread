//
// Created by ASUS on 2023/7/10.
//

#include "includes/monoThread.h"

void monoThread(const long long &n, const std::string &file,
                void (*pMonoMethod)(const long long &n,
                                    std::vector<long long> &primes)) {
#ifndef NDEBUG
  std::cerr << __func__ << std::endl;
#endif

  // check if pMonoMethod is null
  if (pMonoMethod == nullptr)
    throw std::runtime_error("Null pointer exception.");

  auto results =
      timer(monoThreadSieve, "Time elapsed sieveing: ", n, pMonoMethod);
  auto primes = results.first;
  auto duration = results.second;

  auto writeResults =
      timer(writeToFileMonoT, "Time elapsed writing to file: ", primes, file);
  if (writeResults.first != 0)
    throw std::runtime_error("Error when writing to file");

  auto durationWrite = writeResults.second;

  // output total time elapsed
  std::cout << "Total time elapsed: "
            << double(duration + durationWrite) / 1000000000 << " seconds."
            << std::endl;

  // output file and result size
  std::cout << "Done. Check " << file << " for " << primes.size() << " results."
            << std::endl;
}