import <iostream>;

import mainmodule;

template <std::size_t Size>
struct MyArray{
    std::size_t data_[Size]{};
};

struct data{
    constexpr std::size_t get_double_len() const{
        return len*2;
    }
    std::size_t len;
};

//template <std::size_t Size>
//constexpr MyArray<Size> create_array(data d){
//    MyArray<d.get_double_len()> arr;
//	return arr;
//}

int main(){

	MyArray<data{5}.get_double_len()> arr;
	return arr.data_[5];

	//auto arr_ = create_array(data{5});
    //return arr.data_[5];
}