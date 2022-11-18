import <iostream>;

import mainmodule;

int main(){
	int *y; //pointer variable
	ptt::Data* x{new ptt::Data}; //object x
	int z; //local variable of main
	
	y = (int*)x;

	std::cout << "Private value of age is: " << *(y++) << std::endl; //output is 21
	std::cout << "Public value of id is: " << *(y++) << std::endl; //output is 54
	std::cout << "Public value of id is: " << x->id << std::endl; //output is 54

	ptt::A a;
    int* p = (int*)&a;
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
    *p = 3;
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
    p++;
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
    *p = 9;
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
    p--;
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
    std::cout << "x = " << *p << std::endl;
    p++;
    std::cout << "y = " << *p << std::endl;
    return 0;
}