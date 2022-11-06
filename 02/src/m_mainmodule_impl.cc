export module mainmodule:print;

import <iostream>;
import <string>;

export namespace mainmodule{void printvar(auto var) {
    std::cout << var << "\n";
}};