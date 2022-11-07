module;

#include <vector>

export module mainmodule:print;

import <iostream>;
import <string>;

export namespace mainmodule{void printvar(std::vector<std::vector<int>> var) {
    int var_{var[0][0]};
    std::cout << var_ << "\n";
}};