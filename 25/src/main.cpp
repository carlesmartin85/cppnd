import <iostream>;
import <string>;
import <cstring>;
import <charconv>;

import mainmodule;

#include "../fmt/format"

int main(){

	{
		long double d { 3.14L };
		std::string s { std::to_string(d) };
		std::cout << s << std::endl;
	}

	{
		const std::string toParse{"   0x123USD"};
		size_t index{0};
		int value{std::stoi(toParse, &index, 0)}; // base has been set to 0 so that literal string parse takes into account its own base (e.g. 0x for Octal)
		std::cout << fmt::format("Parsed value: {}", value) << std::endl;
		std::cout << fmt::format("First non-parsed character: '{}'", toParse[index]) << std::endl;
	}

	{
		double d{3.1415 / 2.3};
		std::cout << fmt::format("|{:12g}|", d) << std::endl;
		std::cout << fmt::format("|{:12.4}|", d) << std::endl;
		std::cout << fmt::format("|{:12e}|", d) << std::endl;
	}

}