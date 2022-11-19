import <iostream>;
import <algorithm>;
import <vector>;
import <functional>;

import mainmodule;

int main(){

	std::vector<int> data{1, 2, 3, 4, 5, 6, 7};
	std::cout << data[0] << std::endl;

	// Find by value
	auto it = std::find(data.begin(), data.end(), 5);
	std::cout << *it << std::endl;

	// *it == 5
	it = std::find(data.begin(), data.end(), 42);
	std::cout << *it << std::endl;
	// it = data.end()

	// Find using a negation of a predicate
	auto is_even = [](int v){ return v%2 == 0;};
	it = std::find_if_not(data.begin(), data.end(), is_even);
	std::cout << *it << std::endl;
	// *it == 1

	// same as
	it = std::find_if(data.begin(), data.end(), std::not_fn(is_even));
	std::cout << *it << std::endl;
	// *it == 1
}