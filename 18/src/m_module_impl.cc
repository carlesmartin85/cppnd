module;

#include <optional>

export module mainmodule:cmp;

import <iostream>;
import <initializer_list>;

export namespace cmp{

	std::optional<int> getData(bool giveIt){
		if (giveIt){
			return 42;
		}
		return std::nullopt; // or simply return {};
	}

	int makeSum(std::initializer_list<int> values){
		int total{0};
		for (int value : values){
			total += value;
		}
		return total;
	}

};