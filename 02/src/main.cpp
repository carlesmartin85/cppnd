import <iostream>;
import <string>;

import mainmodule;

int main() {
    // Declaring and initializing an int variable.
    int a = 9;
    
    // Declaring a string variable without initializing right away.
    std::string b;
    
    // Initializing the string b.
    b = "Here is a string";

    mainmodule::printvar(a);
    mainmodule::printvar(b);
}