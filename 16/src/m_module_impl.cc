export module mainmodule:cmp;

import <iostream>;

export namespace cmp{

	void func1(int i, char c){
		std::cout << "The value of i is " << i << std::endl;
		std::cout << "The value of c is " << c << std::endl;
    }

	int func2(int i, int j){
		return i + j;
    }

	void func3(){
		std::cout << "Inside function: " << __func__ << std::endl;
	}

	int addNumbers(int a, int b) { return a + b; }
	double addNumbers(double a, double b) { return a - b; }

	[[nodiscard("Secret key has not been used...")]] int secretkey(){
		return 42;
	}

};