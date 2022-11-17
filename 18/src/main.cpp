import <iostream>;
import <initializer_list>;

import mainmodule;

int main(){

	auto what = cmp::getData(false);

	if(what.has_value()){
		std::cout << what.value() << std::endl;
	}else{
		std::cout << "Variable \'what\' has no value..." << std::endl;
	}
	
	std::initializer_list<int> arr{10, 20, 30};
	std::cout << cmp::makeSum(arr) << std::endl;

}