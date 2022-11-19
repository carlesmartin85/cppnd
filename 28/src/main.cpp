import <iostream>;
import <cstring>;
import <ranges>;
import <numbers>;

import mainmodule;

#include "../fmt/format"

int main(){

	// Basic format returns a std::string
	std::string simple = fmt::format("The {} horsemen of {}\n", 4, "apocalypse"); // simple == "The 4 horsemen of apocalypse"

	std::cout << simple;

	auto is_even = [](int v){ return v % 2 == 0; };
	for (auto v : std::views::iota(1, 7)){
		// Output using and output iterator
		fmt::format_to(std::ostreambuf_iterator(std::cout), "is_even({}) == {}\n", v, is_even(v));
	}

	auto pi5 = fmt::format("{:.5}\n", std::numbers::pi);
	std::cout << pi5;

	int width = 10;
	int precision = 3;
	// Formatting arguments can be provided as part of the argument list
	auto pivar = fmt::format("{:^{}.{}}\n", std::numbers::pi, width, precision);
	std::cout << pivar;

}