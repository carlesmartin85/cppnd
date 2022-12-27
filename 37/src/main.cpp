#include <iostream>

#pragma pack(1)
typedef struct Uint8_t{
	public:
	  Uint8_t(uint8_t x_) : x(x_){};
	  Uint8_t operator +(const Uint8_t& obj) {
		Uint8_t temp(uint8_t(0));
		temp.x = this->x + obj.x;
		return temp;
	  }
	  friend std::ostream& operator<< (std::ostream& os, const Uint8_t& obj){
		os << int(obj.x);
		return os;
	  }
	private:
	  uint8_t x;

} uint8_t_;
#pragma pack(0)


auto add(auto a, auto b){
    return a+b;
}

int main(){

   std::cout << add(255UL, 1UL) << "\n"; // Working with 8 bytes...
   std::cout << add(uint8_t_(255), uint8_t_(1)) << "\n"; // Working with 1 byte and overflow...

   std::cout << sizeof(add(255UL, 1UL)) << "\n"; // 8 bytes...
   std::cout << sizeof(add(uint8_t_(255), uint8_t_(1))) << "\n"; // 1 byte...

}