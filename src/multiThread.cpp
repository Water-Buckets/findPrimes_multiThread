//
// Created by ASUS on 2023/7/7.
//
#include "includes/multiThread.h"
#include "includes/preSieve.h"
#include "includes/sieveMethods.h"
#include "includes/preSieveMethods.h"

// 多线程筛选素数
void multiThread(const int &threads, const long long &n, const std::string &file,
                 void (*pMultiMethod)(const long long &lL, const long long &uL, std::vector<long long> &primes,
                                      const std::vector<long long> &preSievedPrimes),
                 void (*pPreSieveMethod)(const long long &n, std::vector<long long> &primes)) {

    // 记录预筛开始时间
    auto startPre = std::chrono::steady_clock::now();

    // 计算sqrt(n)
    long long sqrtN = std::sqrt(n);

    // 向量存储预筛结果
    std::vector<long long> preSievedPrimes;

    // 根据m调用预筛算法
    (*pPreSieveMethod)(sqrtN, preSievedPrimes);

    // 记录预筛结束时间
    auto endPre = std::chrono::steady_clock::now();

    // 计算预筛时间
    auto diffPre = std::chrono::duration_cast<std::chrono::nanoseconds>(endPre - startPre);
    long long durationPre = diffPre.count();

    // 输出预筛时间
    std::cout << "Time elapsed pre-sieveing:"
              << double(durationPre) / 1000000000 << " seconds." << std::endl;

    // 记录筛选开始时间
    auto start = std::chrono::steady_clock::now();

    // threads个线程的筛选结果
    std::vector<std::vector<long long>> primesVec(threads);

    // 每个线程筛选的数值范围
    long long perThread = (n - sqrtN) / threads;

    // 向量存储threads个线程
    std::vector<std::thread> vThread;

    if (preSievedPrimes.empty()) throw std::runtime_error("Empty preSievedPrimes!");

    // 启动threads个筛选线程
    for (int i = 0; i < threads; ++i) {

        // 计算每个线程的下限上限
        long long lL = sqrtN + i * perThread + 1;
        long long uL = sqrtN + (i + 1) * perThread;

        // 最后一个线程上限为n
        if (i == threads - 1) uL = n;

        // 启动线程,调用sievePrimes筛选素数
        std::thread thr((*pMultiMethod), lL, uL,
                        std::ref(primesVec[i]), std::cref(preSievedPrimes));

        // 将线程加入向量
        vThread.emplace_back(std::move(thr));
    }

    // 等待所有线程结束
    for (auto &thr: vThread) if (thr.joinable()) thr.join();

    // 记录结束时间
    auto end = std::chrono::steady_clock::now();

    // 计算筛选用时
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long duration = diff.count();

    // 输出筛选用时
    std::cout << "Time elapsed sieveing:"
              << double(duration) / 1000000000 << " seconds." << std::endl;

    // 记录开始写入时间
    auto startWrite = std::chrono::steady_clock::now();

    // 打开输出文件
    std::ofstream outfile(file);

    // 判断打开是否成功
    if (!outfile.is_open()) throw std::runtime_error("Failed to open file.");

    // 输出预筛结果
    for (long long i: preSievedPrimes) outfile << i << " ";

    // 输出筛选结果
    long long totalSize = preSievedPrimes.size();
    for (auto &vec: primesVec) {
        for (long long i: vec) outfile << i << " ";
        totalSize += vec.size();
    }

    // 关闭文件
    outfile.close();

    // 记录结束写入时间
    auto endWrite = std::chrono::steady_clock::now();

    // 计算写入文件时间
    auto diffWrite = std::chrono::duration_cast<std::chrono::nanoseconds>(endWrite - startWrite);
    long long durationWrite = diffWrite.count();

    // 输出写入文件时间
    std::cout << "Time elapsed writing to file: "
              << double(durationWrite) / 1000000000 << " seconds." << std::endl;

    // 输出总时间
    std::cout << "Total time elapsed: "
              << double(durationPre + duration + durationWrite) / 1000000000 << " seconds." << std::endl;

    // 提示输出结果数量
    std::cout << "Done. Check " << file << " for "
              << totalSize << " results." << std::endl;

}