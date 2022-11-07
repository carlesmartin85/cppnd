#include <vector>

import <iostream>;

import mainmodule;

int main()
{
    // Declaring and initializing a vector<int> container.
    std::vector<std::vector<int>> board{{0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 1, 0}};

    mainmodule::printvar(board);
}