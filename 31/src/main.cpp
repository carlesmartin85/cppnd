#include <iostream>
#include <memory>

template <std::size_t Size>
struct MyArray{
    std::size_t data_[Size]{};
};

struct data{
    static constexpr std::size_t get_double_len() {return len*2;}

    data(std::size_t val){
        len_ = len.allocate(1);
        if (std::is_constant_evaluated()){std::construct_at(&len_[0]);}
        len_[0] = val;
    }

    void deallocate(){
        len_.deallocate(len_, 1);
    }

    std::size_t* len_;
    static constexpr std::allocator<std::size_t> len;
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