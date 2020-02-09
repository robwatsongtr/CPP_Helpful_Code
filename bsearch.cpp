//
//  main.cpp
//  BinarySeachCPPimplem
//	re-implementing binary search
// Rob Watson from Javascript code by Robert Diamond,

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>

// binary search function that returns a couple values needs to be a struct
// in C and C++ because functions in those languages can only do one return value
struct BSearchResult {
    int idx;
    int ops;

    BSearchResult(int i, int o) : idx(i), ops(o) {}
};

// declare a struct called 'bsearch' of type BSearchResult
struct BSearchResult bsearch(int haystack[], int needle);

int main() {
    int randomArrayints[20];

    for (int idx = 0; idx < 20; ++idx) {
        randomArrayints[idx] = rand() % 20 + 1; // need a primer on modulo
    }

    std::sort(randomArrayints, randomArrayints + 20);
    auto result = bsearch(randomArrayints, randomArrayints[3]); // look for 3
	std::cout << result.idx << "," << result.ops << std::endl;
}

struct BSearchResult bsearch(int haystack[], int needle) {
    int min = 0;
    int max = 20;
    int ops = 0; // ops is the number of guesses?

	std::cout << "Looking For: " << needle << std::endl;

    while (min < max) {
        int idxGuess = floor((min+max)/2);
        std::cout << "Min, max, idxGuess " << min << ", " << max << ", "
			<< idxGuess << ", " << haystack[idxGuess] << std::endl;

        if(haystack[idxGuess] == needle) {
            return BSearchResult(idxGuess, ops);
        } else if (haystack[idxGuess] > needle) {
            max = idxGuess;
        } else {
            min = idxGuess + 1;
        }
        ops++;
      }
    return BSearchResult(-1, ops);
}
