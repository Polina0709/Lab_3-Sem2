//
//  count.cpp
//  Lab-3
//
//  Created by Polya Melnik on 30.05.2024.
//

#include "count.hpp"
#include <thread>
#include <mutex>

std::unordered_map<int, int> countNumbersSequential(const std::vector<int>& arr) {
    std::unordered_map<int, int> countMap;
    for (std::vector<int>::size_type i = 0; i < arr.size(); ++i) {
        countMap[arr[i]]++;
    }
    return countMap;
}

std::unordered_map<int, int> globalCountMap;
std::mutex mtx;

void countNumbersInRange(const std::vector<int>& arr, std::vector<int>::size_type start, std::vector<int>::size_type end) {
    std::unordered_map<int, int> localCountMap;
    for (std::vector<int>::size_type i = start; i < end; ++i) {
        localCountMap[arr[i]]++;
    }

    std::lock_guard<std::mutex> lock(mtx);
    for (const auto& pair : localCountMap) {
        globalCountMap[pair.first] += pair.second;
    }
}

std::unordered_map<int, int> countNumbersParallel(const std::vector<int>& arr, int numThreads) {
    globalCountMap.clear();
    std::vector<int>::size_type chunkSize = arr.size() / numThreads;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        std::vector<int>::size_type start = i * chunkSize;
        std::vector<int>::size_type end = (i == numThreads - 1) ? arr.size() : start + chunkSize;
        threads.push_back(std::thread(countNumbersInRange, std::ref(arr), start, end));
    }

    for (std::thread& t : threads) {
        t.join();
    }

    return globalCountMap;
}
