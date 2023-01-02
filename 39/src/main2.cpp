#include <iostream>
#include <string>

int main(){
    
    for (int i=0; i<100'000'000; i++){
        std::string name{"hello, c++ developer"};

        // lvalue reference
        std::string &lvalue_reference = name;

        // rvalue reference
        std::string &&rvalue_reference = std::move(lvalue_reference.c_str());

        rvalue_reference[0] = '1';

        // std::cout << rvalue_reference << std::endl;
        // std::cout << lvalue_reference << std::endl;
    }

    return 0;
}