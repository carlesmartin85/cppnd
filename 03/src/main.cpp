#include <vector>

import <iostream>;
import <string>;

import mainmodule;

int main() {
    // Declaring and initializing a vector<int> container.
    std::vector<std::vector<int>> a{{1, 2}, {3, 4}};

    mainmodule::printvar(a);
}