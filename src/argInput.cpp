//
// Created by ASUS on 2023/7/7.
//
#include "includes/argInput.h"

void argInput(char *argv[]) {
    if (!isNumeric(argv[1]) || !isNumeric(argv[3]) || argv[2][1]) throw std::invalid_argument("Invalid input.");
    int threads = std::stoi(argv[1]);
    char m = argv[2][0];
    long long n = std::stoll(argv[3]);
    std::string file = argv[4];
    if (n <= 1) throw std::invalid_argument("n must be greater than 1.");
#ifndef NDEBUG
    std::cerr << __func__ << ": " << threads << " " << m << " " << n << " " << file << std::endl;
#endif
    switch (m) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
            if (threads > 1) {
                std::cout << "Using Multithread Mode" << std::endl;
                if (m == 'e') {
                    std::cerr << "Error: Trying to use Sieve of Atkin when using multithread mode" << std::endl;
                    exit(0);
                } else if (m == 'g') {
                    std::cerr << "Error: Trying to use wheel sieve when using multithread mode" << std::endl;
                    exit(0);
                }
                multiThread(threads, m, n, file);
                break;
            } else if (threads == 1) {
                std::cout << "Using Monothread Mode" << std::endl;
                monoThread(n, m, file);
                break;
            } else {
                throw std::invalid_argument("Invalid input.");
            }
        default:
            throw std::invalid_argument("Invalid input.");
    }
}