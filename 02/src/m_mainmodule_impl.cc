module;

#include <string>

export module mainmodule:print;

import <iostream>;

export namespace mainmodule{void printvar1(int var) {std::cout << var << "\n";}};
//export namespace mainmodule{void printvar2(std::string var) {std::cout << var << "\n";}};