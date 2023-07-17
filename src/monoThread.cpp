//
// Created by ASUS on 2023/7/10.
//

#include "includes/monoThread.h"

// 单线程筛选素数
void monoThread(const long long &n, const char &m, const std::string &file) {

    // 定义primes向量存储筛选结果
    std::vector<long long> primes;

    // 记录开始时间
    auto start = std::chrono::steady_clock::now();

    // 根据参数m选择不同筛法
    switch (m) {

        // 试除法
        case 'a':
            // 调用试除法算法筛选素数
            trialDivision(n, primes);
            break;

            // 埃拉托色尼筛法
        case 'b':
            // 调用埃拉托色尼筛法算法筛选素数
            eratosthenesSieve(n, primes);
            break;

            // 欧拉筛法
        case 'c':
            // 调用欧拉筛法算法筛选素数
            eulerSieve(n, primes);
            break;

            // 索马拉姆筛法
        case 'd':
            // 调用索马拉姆筛法算法筛选素数
            sundaramSieve(n, primes);
            break;

            // 阿特金筛法
        case 'e':
            // 调用阿特金筛法算法筛选素数
            atkinSieve(n, primes);
            break;

            // 增量筛法
        case 'f':
            // 调用增量筛法算法筛选素数
            incrementalSieve(n, primes);
            break;

            // 轮子筛法
        case 'g':
            // 调用轮子筛法算法筛选素数
            wheelSieve(n, primes);
            break;

    }

    // 记录结束时间
    auto end = std::chrono::steady_clock::now();

    // 计算筛选用时
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long duration = diff.count();

    // 输出结果primes大小和用时
    std::cout << "Found " << primes.size() << " primes in "
              << double(duration) / 1000000000 << " seconds." << std::endl;

    // 记录开始写入时间
    auto startWrite = std::chrono::steady_clock::now();

    // 打开输出文件
    std::ofstream outfile(file);

    // 检查文件打开是否成功
    if (!outfile.is_open()) {
        throw std::runtime_error("Failed to open file.");
    }

    // 将primes中的结果写入文件
    for (auto p: primes) {
        outfile << p << " ";
    }

    // 关闭文件
    outfile.close();

    // 记录结束写入时间
    auto endWrite = std::chrono::steady_clock::now();

    // 计算写入文件用时
    auto diffWrite = std::chrono::duration_cast<std::chrono::nanoseconds>(endWrite - startWrite);
    long long durationWrite = diffWrite.count();

    // 输出结果写入文件用时
    std::cout << "Time elapsed writing to file: "
              << double(durationWrite) / 1000000000 << " seconds." << std::endl;

    // 输出总用时
    std::cout << "Total time elapsed: "
              << double(duration + durationWrite) / 1000000000 << " seconds." << std::endl;

    // 提示输出文件和结果数量
    std::cout << "Done. Check " << file << " for "
              << primes.size() << " results." << std::endl;

}