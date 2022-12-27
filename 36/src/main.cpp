#include <iostream>

template <typename T, size_t size>
void f1(const T (&array)[size]){
    for(T x : array){
        T elem = x;
    }
}

template <typename T, size_t size>
void f2(const T (&array)[size]){
    for(size_t i = 0; i < size; i++){
        T elem = array[i];
    }
}

template <typename T>
struct Span<T> span = array;
void f3(const T (&array)[size]){
    for(size_t i = 0; i < size; i++){
        //
    }
}

int main() {
    int arr[] = {1,2,3,4,99};

    f1(arr);
}
