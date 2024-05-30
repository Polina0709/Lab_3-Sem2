//
//  count.h
//  Lab-3
//
//  Created by Polya Melnik on 30.05.2024.
//

#ifndef COUNT_H
#define COUNT_H

#include <vector>
#include <unordered_map>

// Декларації функцій
std::unordered_map<int, int> countNumbersSequential(const std::vector<int>& arr);
std::unordered_map<int, int> countNumbersParallel(const std::vector<int>& arr, int numThreads);

#endif // COUNT_H

