import <iostream>;
import <cstddef>;
import <array>;
import <vector>;
import <utility>;

import mainmodule;

int main(){
	int i{ 11 };
	cmp::func1(i, 'c');
	std::cout << cmp::func2(1, 2) << std::endl;
	cmp::func3();
	std::cout << cmp::addNumbers(1, 2) << std::endl;
	std::cout << cmp::addNumbers(1., 2.) << std::endl;
	int j{cmp::secretkey()};

	int myArray[]{3, 4, 5, 6, 7, 8};

	int n{std::size(myArray)};
	std::cout << n << std::endl;

	for(auto item : myArray){
		std::cout << item << std::endl;
	}

	{
		using namespace std;
		array<int, 3> arr { 9, 8, 7 };
		cout << "Array size = " << arr.size() << endl;
		cout << "2nd element = " << arr[1] << endl;
	}

	{
		using namespace std;
		// Create a vector of integers.
		vector<int> myVector { 11, 22 };
		// Add some more integers to the vector using push_back().
		myVector.push_back(33);
		myVector.push_back(44);
		cout << "1st element: " << myVector[0] << endl;
		cout << "Last element: " << myVector[myVector.size() - 1] << endl;
	}

	{
		std::pair<double, int> myPair { 1.23, 5 };
		std::cout << myPair.first << " and " << myPair.second << std::endl;
	}
}