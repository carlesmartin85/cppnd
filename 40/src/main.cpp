#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

template<typename T>
std::tuple<bool*, T*> get_trapped_w(const std::vector<T> heightmap, bool* &trapped_w, T* &quantity_w){
    
    size_t size = (size_t)heightmap.size();
    int delta[size -1];

    trapped_w = new bool[size];
    quantity_w = new T[size];

    delta[0] = heightmap[1] - heightmap[0];
    for(size_t i = 1; i < size - 1; i++){
        delta[i] = heightmap[i] - heightmap[i - 1];
        if(delta[i] > 0 && (-delta[i - 1]) > 0){
            trapped_w[i] = true;
            quantity_w[i] = std::min(delta[i], -delta[i - 1]);
            //std::cout << quantity_w[i] << " of trapped water at index " << i << std::endl;
        }
    }
    return std::make_tuple(trapped_w, quantity_w);
}

template<typename T>
T trapped_water(const std::vector<T> &heightmap){
    bool *trapped_w;
    int *quantity_w;
    if(heightmap.size() == 0){
        delete[] trapped_w, quantity_w;
        return 0;
    }
    std::tie(trapped_w, quantity_w) = get_trapped_w<T>(heightmap, trapped_w, quantity_w);
    size_t size = heightmap.size();
    for(size_t i = 0; i < size; i++){
        if(*(trapped_w + i)!=0) {
            delete[] trapped_w, quantity_w;
            return *(quantity_w + i);
        }
    }
    delete[] trapped_w, quantity_w;
    return 0;
}

int main(){

    assert(trapped_water(std::vector<int>{}) == 0);
    // zero case
    std::vector<int> t1 = {0, 0, 0, 0, 0};
    assert(trapped_water(t1) == 0);
    // monotonic cases
    std::vector<int> t2 = {0, 1, 2, 3, 4};
    assert(trapped_water(t2) == 0);
    std::vector<int> t3 = {4, 3, 2, 1, 0};
    assert(trapped_water(t3) == 0);
    // example
    std::vector<int> t4 = {0, 2, 3, 0, 2, 0};
    assert(trapped_water(t4) == 2);

    return 0;
}