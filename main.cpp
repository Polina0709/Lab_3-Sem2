//
//  main.cpp
//  Lab-3
//
//  Created by Polya Melnik on 30.05.2024.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include "count.hpp"

int main() {
    
    std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    // Вимірювання часу для послідовного підрахунку
    auto start = std::chrono::high_resolution_clock::now();
    std::unordered_map<int, int> sequentialResult = countNumbersSequential(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sequentialDuration = end - start;
    std::cout << "Послідовний підрахунок:\n";
    for (const auto& pair : sequentialResult) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "Час виконання послідовного підрахунку: " << sequentialDuration.count() << " секунд\n";

    // Вимірювання часу для паралельного підрахунку
    start = std::chrono::high_resolution_clock::now();
    std::unordered_map<int, int> parallelResult = countNumbersParallel(arr, 4);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelDuration = end - start;
    std::cout << "Паралельний підрахунок:\n";
    for (const auto& pair : parallelResult) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "Час виконання паралельного підрахунку: " << parallelDuration.count() << " секунд\n";

    return 0;
}
