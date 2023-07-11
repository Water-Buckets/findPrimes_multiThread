cmake_minimum_required(VERSION 3.26)
project(findPrimes_multiThread)

set(CMAKE_CXX_STANDARD 23)

add_executable(findPrimes_multiThread src/main.cpp
        src/main.h
        src/argInput.cpp
        src/argInput.h
        src/multiThread.h
        src/multiThread.cpp
        src/sievePrimes.cpp
        src/sievePrimes.h
        src/bits/stdc++.h
        src/monoThread.cpp
        src/monoThread.h
        src/sieves/preSieveMethods.cpp
        src/sieves/preSieveMethods.h
        src/preSieve.cpp
        src/sieves/sieveMethods.cpp
        src/sieves/sieveMethods.h
)

set(CMAKE_EXPORT_COMPILE_COMMANDS=ON)
