//
// Created by ASUS on 2023/7/10.
//

#include "includes/monoThread.h"

// 单线程筛选素数
void monoThread(const long long &n, const char &m, const std::string &file,
                void (*pMonoMethod)(const long long &n, std::vector<long long> &primes)) {
    //
    if (pMonoMethod == nullptr) throw std::runtime_error("Null pointer exception.");

    // 定义primes向量存储筛选结果
    std::vector<long long> primes;

    // 记录开始时间
    auto start = std::chrono::steady_clock::now();

    // 调用筛选方法
    (*pMonoMethod)(n, primes);

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