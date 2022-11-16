export module mainmodule:cmp;

import <iostream>;
import <compare>;

export namespace cmp{

	void func(int i){
    std::strong_ordering result{ i <=> 0 };
	  if (std::is_lt(result)) { std::cout << "less" << std::endl; }
  	if (std::is_gt(result)) { std::cout << "greater" << std::endl; }
	  if (std::is_eq(result)) { std::cout << "equal" << std::endl; }
  }

};