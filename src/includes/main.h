//
// Created by ASUS on 2023/7/7.
//

#ifndef FINDPRIMES_MULTITHREAD_MAIN_H
#define FINDPRIMES_MULTITHREAD_MAIN_H

#include "../bits/stdc++.h"
#include "argInput.h"
#include "multiThread.h"

inline void printHelp() {
  std::cout << "Usage: findprimes [threads] [method] [n] [outputFile]"
            << std::endl;
  std::cout << "You can tell the program to use multiple threads by providing "
               "a number for threads."
            << std::endl;
  std::cout << "Warning: the program will not check if the number of threads "
               "is valid."
            << std::endl;
  std::cout << "If the number of threads is invalid, the program will exit "
               "with an error."
            << std::endl;
  std::cout << "You can tell the program to use a specific method by providing "
               "a character for method."
            << std::endl;
  std::cout << "For method you can choose between 'a' 'b' 'c' 'd' 'e' 'f' 'g'."
            << std::endl;
  std::cout << "a stand for Trial Division" << std::endl;
  std::cout << "b stand for Sieve of Eratosthenes" << std::endl;
  std::cout << "c stand for Sieve of Euler" << std::endl;
  std::cout << "d stand for Sieve of Sundaram" << std::endl;
  std::cout << "e stand for Sieve of Atkin" << std::endl;
  std::cout << "f stand for Incremental Sieve" << std::endl;
  std::cout << "g stand for Wheel Sieve" << std::endl;
  std::cout << "If no arguments are provided, the program will show this help."
            << std::endl;
}

#endif // FINDPRIMES_MULTITHREAD_MAIN_H
