#include <iostream>
#include <sstream>
#include <string>

int main () 
{
    std::string a("1 2 3");

    std::istringstream my_stream(a);

    int n, m, l;
    my_stream >> n >> m >> l;
    std::cout << n << " " << m << " " << l <<"\n";
}