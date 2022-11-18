import <iostream>;
import <string>;

import mainmodule;

int main(){

	char* str{new char[5]};

	str[0] = 'h';
	str[1] = 'o';
	str[2] = 'l';
	str[3] = 'a';
	str[4] = '\0';

	std::cout << str << std::endl;

	char* str_ = ptt::copyString(str);
	char* str__ = ptt::copyString(str_);

	std::cout << str_ << std::endl;
	std::cout << str__ << std::endl;

	char* finalstr = ptt::appendStrings(str, str_, str__);

	std::cout << finalstr << std::endl;

	char ptr[] { "hello" };
	ptr[1] = 'a';
	
	std::cout << ptr << std::endl;

	std::string a { "12" };
	std::cout << a << std::endl;
	std::string b { "34" };
	std::cout << b << std::endl;
	std::string c;
	c = a + b; // c is "1234"
	std::cout << c << std::endl;

}