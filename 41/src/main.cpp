#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

template<typename T>
void get_summits(const std::vector<T> &heightmap, bool* &summits){
    
    size_t size = heightmap.size();
    int delta;

    summits = new bool[size];

    size_t baton{0};
    bool flat{false};
    bool up{true};
    
    for(size_t i = 0; i < size; i++){
        delta = heightmap[i + 1] - heightmap[i];
        if(delta < 0 && up){
            for(size_t j = baton; j < i + 1; j++){
                summits[j] = true;
            }
            up = false;
        }else if(delta > 0){
            up = true;
            if(i == size - 1) summits[i] = true;
            baton = i + 1;
        } else {
            if(flat == false) baton = i;
            flat = true;
        }
    }
}

template<typename T>
void get_ponds(const std::vector<T> &heightmap, bool* &summits, T* &ponds){
    std::vector<std::vector<std::vector<size_t>>> edges{};
    size_t size = heightmap.size();
    ponds = new T[size];
    bool flag{false};
    for(size_t i = 0; i < size; i++){
        std::vector<std::vector<size_t>> edges_{};
        for(size_t j = size - 1; j > i; j--){
            if(!summits[i] || !summits[j]) continue;
            flag = true;
            std::vector<size_t> edges__ = {};
            edges__.push_back(i);
            edges__.push_back(j);
            edges_.push_back(edges__);
        }
        if(flag){
            edges.push_back(edges_);
            flag = false;
        }
    }
    for(size_t i = 0; i < heightmap.size(); i++){
        ponds[i] = (T)0;
    }
    for(std::vector<std::vector<size_t>> edges_ : edges){
        size_t dick_i{edges_[0][1]};
        for(std::vector<size_t> edges__ : edges_){
            if(heightmap[edges__[1]] >= heightmap[dick_i]) dick_i = edges__[1];
        }
        for(size_t i = edges_[0][0]; i < dick_i + 1; i++){
            if(ponds[i] < std::min(heightmap[edges_[0][0]], heightmap[dick_i])) ponds[i] = std::min(heightmap[edges_[0][0]], heightmap[dick_i]);
        }
    }
}

template<typename T>
T trapped_water(const std::vector<T> &heightmap){
   T result{0};
   bool *summits;
   get_summits(heightmap, summits);
   T *ponds;
   get_ponds(heightmap, summits, ponds);
   for(size_t i = 0; i < heightmap.size(); i++){
    if((ponds[i] - heightmap[i]) > (T)0){
        result += std::abs(ponds[i] - heightmap[i]);
    }
    }
   return result;
}

int main(){

    // empty case
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
    // two more "real" test cases
    std::vector<int> t5 = {5, 1, 2, 9, 3, 0, 2, 4, 8, 7, 6, 5};
    assert(trapped_water(t5) == 30);
    std::vector<int> t6 = {9, 8, 9, 2, 5, 2, 9, 8, 9};
    assert(trapped_water(t6) == 20);

    return 0;
}