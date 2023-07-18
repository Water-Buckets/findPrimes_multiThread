//
// Created by ASUS on 2023/7/10.
//

#ifndef FINDPRIMES_MULTITHREAD_MONOTHREAD_H
#define FINDPRIMES_MULTITHREAD_MONOTHREAD_H

#include "../bits/stdc++.h"
#include "sieveMethods.h"

void monoThread(const long long &n, const char &m, const std::string &file,
                void (*pMonoMethod)(const long long &n, std::vector<long long> &primes));

#endif // FINDPRIMES_MULTITHREAD_MONOTHREAD_H
