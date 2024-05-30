//
//  UnitTestCount.m
//  UnitTestCount
//
//  Created by Polya Melnik on 30.05.2024.
//

#import <XCTest/XCTest.h>
#import "count.hpp"

@interface UnitTestCount : XCTestCase

@end

@implementation UnitTestCount

- (void)testCountNumbersSequential {
    std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    std::unordered_map<int, int> expected = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};

    std::unordered_map<int, int> result = countNumbersSequential(arr);

    for (auto& pair : result) {
        XCTAssertEqual(pair.second, expected[pair.first]);
    }
}

- (void)testCountNumbersParallel {
    std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    std::unordered_map<int, int> expected = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};

    std::unordered_map<int, int> result = countNumbersParallel(arr, 4);

    for (auto& pair : result) {
        XCTAssertEqual(pair.second, expected[pair.first]);
    }
}

@end
