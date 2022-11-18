import <iostream>;
using namespace std;

class Data{
	private:
	int age=21;
	public:
	int id=54;
};

 
class A {
private:
    int x;
    int y;
};

import mainmodule;

int main(){
	int *y; //pointer variable
	Data* x{new Data}; //object x
	int z; //local variable of main
	
	y = (int*)x;

	cout << "Private value of age is: " << *(y++) << endl; //output is 21
	cout << "Public value of id is: " << *(y++) << endl; //output is 54
	cout << "Public value of id is: " << x->id << endl; //output is 54

	A a;
    int* p = (int*)&a;
	cout << p << endl;
	cout << *p << endl;
    *p = 3;
	cout << p << endl;
	cout << *p << endl;
    p++;
	cout << p << endl;
	cout << *p << endl;
    *p = 9;
	cout << p << endl;
	cout << *p << endl;
    p--;
	cout << p << endl;
	cout << *p << endl;
    cout << "x = " << *p << endl;
    p++;
    cout << "y = " << *p << endl;
    return 0;
}