//
// Created by ASUS on 2023/7/7.
//
#include "includes/argInput.h"

void argInput(char *argv[]) {

#ifndef NDEBUG
  std::cerr << __func__ << std::endl;
#endif

  // 检查输入是否合法
  if (!isNumeric(argv[1]) || !isNumeric(argv[3]) || argv[2][1])
    throw std::invalid_argument("Invalid input.");

  // 将输入转换为合适的类型
  int threads = std::stoi(argv[1]);
  char m = argv[2][0];
  long long n = std::stoll(argv[3]);
  std::string file = argv[4];

  // 检查输入是否合法
  if (n <= 1)
    throw std::invalid_argument("n must be greater than 1.");

#ifndef NDEBUG
  std::cerr << __func__ << ": " << threads << " " << m << " " << n << " "
            << file << std::endl;
#endif

  if (threads == 1) {
    std::cout << "Using monoThread mode" << std::endl;
    void (*pMonoMethod)(const long long &n, std::vector<long long> &primes);
    pMonoMethod = switchMonoMethods(m);

#ifndef NDEBUG
    std::cerr << "pMonoMethod: " << pMonoMethod << std::endl;
#endif

    monoThread(n, file, pMonoMethod);
  } else if (threads > 1) {
    try {
      std::cout << "Using multiThread mode" << std::endl;
      if (m == 'e' || m == 'g')
        throw std::invalid_argument(
            "MultiThread mode does not support this algorithm.");
      void (*pPreSieveMethod)(const long long &n,
                              std::vector<long long> &primes);
      pPreSieveMethod = switchMonoMethods(m);

#ifndef NDEBUG
      std::cerr << "pPreSieveMethod: " << &pPreSieveMethod << std::endl;
#endif

      void (*pMultiMethod)(const long long &lL, const long long &uL,
                           std::vector<long long> &primes,
                           const std::vector<long long> &preSievedPrimes);
      pMultiMethod = switchMultiMethods(m);

#ifndef NDEBUG
      std::cerr << "pMultiMethod: " << &pMultiMethod << std::endl;
#endif

      multiThread(threads, n, file, pMultiMethod, pPreSieveMethod);
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << std::endl;
      std::exit(0);
    } catch (std::runtime_error &e) {
      std::cerr << e.what() << std::endl;
      std::cerr
          << "Please submit you issues here: "
             "https://github.com/Water-Buckets/findPrimes_multiThread/issues"
          << std::endl;
      std::exit(0);
    }
  } else
    throw std::invalid_argument("Invalid number of threads");
}