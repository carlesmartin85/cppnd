import <iostream>;

import airline;

int main(){

	int *myArray1 = new int[]{0, 1, 2, 3};

	class air::MyArray myArray2;

	int sample{myArray2.getElement(0)};

	std::cout << sample << std::endl;

	air::Employee anEmployee1 { 'J', 'D', 42, 80'000 }; // Uniform initialization

	air::Employee anEmployee2{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 42,
		.salary = 80'000}; // Designated initialization
}