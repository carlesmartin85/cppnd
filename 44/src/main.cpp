#include <vector>
#include <cassert>

#include <iostream>

/* The problem:
Given a list of integers, determine the smallest missing 
positive integer.

Importantly your solution must run in O(n) time, and while 
you are permitted to modify the input, you can only use 
constant additional memory.

Examples:
{3, -1, 0, 4, 1} -> 2
{1, 2, 3} -> 4
*/


int lowest_missing(std::vector<int> data) {
    for(int _ : data){std::cout << _ << " ";}
    std::cout << std::endl;
    // O(n) "sort"
    for(int i = 0; i < data.size(); i++) {
        while (data[i] > 0 && // if a positive number
               data[i] - 1 < std::ssize(data) && // and does fit in this array
               data[i] != data[data[i] - 1] && // this is not noop
               data[i] - 1 != i) // and not in correct place
            {
            std::swap(data[i], data[data[i] - 1]); // put it in correct place
            for(int _ : data){std::cout << _ << " ";}
            std::cout << std::endl;
            }
        std::cout << std::endl;
    }
    // O(n) because each number is swapped at most twice
    // - first pulled to the current index
    // - then put into final place

    // O(n) search
    for(int _ : data){std::cout << _ << " ";}
    std::cout << std::endl;
    for(int i = 0; i < data.size(); i++) {
        if (data[i] - 1 != i) return i + 1;
    }
    return data.size() + 1;
}

int main() {
    std::cout << lowest_missing({9,8,7,5,3,6,4,2,1}) << std::endl;
    
    //assert(lowest_missing_({1,2,0}) == 3);
    //assert(lowest_missing_({3,4,-1,1}) == 2);
    //assert(lowest_missing_({7,8,9,11,12}) == 1);
    //assert(lowest_missing_({9,8,7,6,5,4,3,2,1}) == 10);
    //assert(lowest_missing_({9,8,7,4,3,2,1}) == 5);
    //assert(lowest_missing_({1,1}) == 2);
}