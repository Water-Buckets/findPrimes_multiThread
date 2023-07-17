cmake_minimum_required(VERSION 3.15)
project(findPrimes_multiThread)

set(CMAKE_CXX_STANDARD 17)

add_executable(findPrimes_multiThread src/main.cpp
        src/includes/main.h
        src/argInput.cpp
        src/includes/argInput.h
        src/includes/multiThread.h
        src/multiThread.cpp
        src/includes/sievePrimes.h
        src/bits/stdc++.h
        src/monoThread.cpp
        src/includes/monoThread.h
        src/includes/preSieveMethods.h
        src/includes/sieveMethods.h
        src/sieves/sieveMethods.cpp
        src/sieves/preSieveMethods.cpp
)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DNDEBUG)
endif ()

find_package(Threads REQUIRED)
target_link_libraries(findPrimes_multiThread Threads::Threads)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
