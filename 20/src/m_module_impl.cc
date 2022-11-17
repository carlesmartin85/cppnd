export module airline:ticket;

import <string>;

export namespace air{

	class MyArray{
	public:
		MyArray() : m_array{0, 1, 2, 3} {}
		int getElement(int elem){return m_array[elem];}

	private:
		int m_array[4];
    };

	struct Employee{
		char firstInitial;
		char lastInitial;
		int employeeNumber;
		int salary{75'000};
	};
}