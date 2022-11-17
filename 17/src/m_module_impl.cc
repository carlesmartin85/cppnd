export module mainmodule:cmp;

import <iostream>;
import <cstddef>;
import <array>;
import <vector>;
import <utility>;

export namespace cmp{

	void func(){

		std::array<int, 3> myArr { 1, 2, 3 };
		std::cout << myArr[0] << " - " << myArr[1] << " - " << myArr[2] << std::endl;
		
		std::vector<int> myVect { 1, 2, 3};
		std::cout << myVect.size() << std::endl;
		
		std::pair<double, int> myPair { 1.23, 5 };
		std::cout << myPair.first << " - " << myPair.second << std::endl;

		//auto [x, y] { myPair }; // Binding...
		//std::cout << x << std::endl;
		//std::cout << y << std::endl;

    }

};