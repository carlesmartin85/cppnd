module;

#include <vector>

export module mainmodule:print;

import <iostream>;

export namespace mainmodule{void printboard(std::vector<std::vector<int>> var) {
    //int var_{var[0][0]};
    //std::cout << var_ << "\n";
    for(std::vector<int> var_ : var){
        for(int var__ : var_){
            std::cout << var__ << " ";
        }
        std::cout << "\n";
    }
}};