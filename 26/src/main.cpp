import <iostream>;

import mainmodule;

class Simple{
  public:
	Simple() { std::cout << "Simple constructor called!" << std::endl; }
	~Simple() { std::cout << "Simple destructor called!" << std::endl; }
};

int main(){

	int *ptr{new int};
	std::cout << "ptr = " << *ptr << " at " << ptr << std::endl;
	*ptr = 5;
	std::cout << "ptr = " << *ptr << " at " << ptr << std::endl;
	delete ptr;
	std::cout << "ptr = " << *ptr << " at " << ptr << std::endl;
	ptr = nullptr;
	if(ptr != nullptr){std::cout << "ptr = " << *ptr << " at " << ptr << std::endl;}

	Simple *mySimpleArray{new Simple[4]};
	// Use mySimpleArray...
	delete[] mySimpleArray;
	mySimpleArray = nullptr;
}