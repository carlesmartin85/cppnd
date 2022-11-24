import <iostream>;

import mainmodule;

template <std::size_t Size>
struct MyArray{
    std::size_t data_[Size]{};
};

struct data{
    constexpr static std::size_t get_double_len(){ return len*2; }
    constexpr static std::size_t len{5};
};

constexpr auto create_array(data d) {
    return MyArray<d.get_double_len()>();
}

int main(){
	//MyArray<data{5}.get_double_len()> arr;
	//return arr.data_[5];

    constexpr auto arr = create_array(data{});
    return arr.data_[5];
}