import <iostream>;

import mainmodule;

template <std::size_t Size>
struct MyArray{
    std::size_t data_[Size]{};
};

struct data{
    static constexpr std::size_t get_double_len() {return len*2;}
    std::size_t len;
};

constexpr auto create_array( data d ) noexcept {
    return MyArray<d.get_double_len()>();
}

int main(){
	//MyArray<data{5}.get_double_len()> arr;
	//return arr.data_[5];
    
    constexpr data d{5};
    constexpr auto arr = create_array(d);
    std::cout << arr.data_[5] << std::endl;
    //return arr.data_[5];
}