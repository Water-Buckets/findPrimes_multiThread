//
// Created by ASUS on 2023/7/7.
//
#include "argInput.h"

void argInput(char *argv[]) {
    if (!isNumeric(argv[1]) || !isNumeric(argv[3]) || argv[2][1]) throw std::invalid_argument("Invalid input.");
    int threads = std::stoi(argv[1]);
    char m = argv[2][0];
    long long n = std::stoll(argv[3]);
    std::string file = argv[4];
    if (n <= 1)
        throw std::invalid_argument("n must be greater than 1.");
    switch (m) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
            std::cerr << "Warning: Sieve Of Atkin can't be used Multithreaded, forcing threads to be 1" << std::endl;
            threads = 1;
        case 'f':
        case 'g':
            if (threads > 1) {
                std::cout << "Using Multithread Mode" << std::endl;
                multiThread(threads, m, n, file);
                break;
            } else if (threads == 1) {
                std::cout << "Using Monothread Mode" << std::endl;
                monoThread(n, m, file);
                break;
            }
        default:
            throw std::invalid_argument("Invalid input.");
    }
}