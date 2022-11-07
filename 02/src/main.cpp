#include <string>

import <iostream>;

import mainmodule;

int main() {
    // Declaring and initializing an int variable.
    int a = 9;
    
    // Declaring a string variable without initializing right away.
    std::string b;
    
    // Initializing the string b.
    b = "Here is a string";

    mainmodule::printvar1(a);
    //mainmodule::printvar2(b);
}