import <iostream>;

import airline;

int main(){

	{
		air::Employee *anEmployee1{new air::Employee};

		air::Employee *anEmployee2{anEmployee1};

		if (anEmployee1){
			std::cout << (*anEmployee1).m_salary << std::endl;
			std::cout << anEmployee2->m_salary << std::endl;
		}

		delete anEmployee1;
		anEmployee2 = nullptr;
	}

	{
		int i{8};
		int* myIntegerPointer{&i};

		std::cout << *myIntegerPointer << std::endl;
	}
}