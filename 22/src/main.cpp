import <iostream>;

import mainmodule;

#include "../fmt/format"

int main(){
	std::cout << fmt::format("x has value {} and y has value {}.", 1, 2) << std::endl;
	return 0;
}
