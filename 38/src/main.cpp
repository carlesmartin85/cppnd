#include <iostream>

namespace  copy{

// Default-copying policy...
template<typename T>
class def{
public:
    T *_data{nullptr};
    void log(const char* msg){
        std::cout << "[ " << this << "\033[1;31m @ \033[0m" << _data << " ] " << msg << std::endl;
    }
};

// No-copying policy...
template<typename T>
class nocopy : public def<T> {
    using def<T>::log;
    using def<T>::_data;

public:
    // 0. Default constructor without initialization
    nocopy(){
        _data = (T *)malloc(sizeof(T));
        log("No-Copy Policy| Default Constructor Call");
    };
    // 1. Default constructor with initialization
    nocopy(T val){
        _data = (T *)malloc(sizeof(T));
        *_data = val;
        log("No-Copy Policy| Default Constructor Call with initialization");
    };
    // 2. Copy constructor
    nocopy(const nocopy<T> &){
        log("No-Copy Policy| Copy Constructor Call");
    };
    // 3. Assignment operator
    nocopy &operator=(const nocopy<T> &){
        log("No-Copy Policy| Assignment Operator Call");
    };
    // 4. Move constructor
    nocopy(nocopy &&source){
        log("No-Copy Policy| Move Constructor Call");
        _data = source._data;
        source._data = nullptr;
    }
    // 5. Move assignment operator
    nocopy &operator=(nocopy &&source){
        log("No-Copy Policy| Move Assignment Operator Call");
        if (this == &source){return *this;}
        free(_data);
        _data = source._data;
        source._data = nullptr;
        return *this;
    }
    // 6. Destructor
    ~nocopy(){
        log("No-Copy Policy| Destructor Call");
        if (_data != nullptr){free(_data);}
    };
    T* getdata(){
        return _data;
    }
};

// Exclusive-copying policy...
template<typename T>
class exclusive : public def<T> {
    using def<T>::log;
    using def<T>::_data;
public:
    // 0. Default constructor without initialization
    exclusive(){
        _data = (T *)malloc(sizeof(T));
        log("No-Copy Policy| Default Constructor Call");
    };
    // 1. Default constructor with initialization
    exclusive(T val){
        _data = (T *)malloc(sizeof(T));
        *_data = val;
        log("Exclusive-Ownership Policy| Default Constructor Call with initialization");
    }
    // 2. Copy constructor
    exclusive(exclusive &source){
        _data = source._data;
        source._data = nullptr;
        log("Exclusive-Ownership Policy| Copy Constructor Call");
    }
    // 3. Assignment operator
    exclusive &operator=(exclusive &source){
        if(this == &source){return *this;} // Auto-assignment protection
        _data = source._data;
        source._data = nullptr;
        log("Exclusive-Ownership Policy| Assignment Operator Call");
        return *this;
    }
    // 4. Move constructor
    exclusive(exclusive &&source){
        log("Exclusive-Copy Policy| Move Constructor Call");
        _data = source._data;
        source._data = nullptr;
    }
    // 5. Move assignment operator
    exclusive &operator=(exclusive &&source){
        log("Exclusive-Copy Policy| Move Assignment Operator Call");
        if (this == &source){return *this;}
        free(_data);
        _data = source._data;
        source._data = nullptr;
        return *this;
    }
    // 6. Destructor
    ~exclusive(){
        if (_data != nullptr){
            log("Exclusive-Ownership Policy| Destructor Call");
            free(_data);
        }
            
    }
    T* getdata(){
        return _data;
    }
};

// Deep-copying policy...
template<typename T>
class deep : public def<T> {
    using def<T>::log;
    using def<T>::_data;
public:
    // 0. Default constructor without initialization
    deep(){
        _data = (T *)malloc(sizeof(T));
        log("No-Copy Policy| Default Constructor Call");
    };
    // 1. Default constructor with initialization
    deep(T val){
        _data = (T *)malloc(sizeof(T));
        *_data = val;
        log("Deep-Copy Policy| Default Constructor Call with initialization");
    }
    // 2. Copy constructor
    deep(deep &source){
        _data = (T *)malloc(sizeof(T));
        *_data = *source._data;
        log("Deep-Copy Policy| Copy Constructor Call");
    }
    // 3. Assignment operator
    deep &operator=(deep &source){
        if(this == &source){return *this;} // Auto-assignment protection
        _data = (T *)malloc(sizeof(T));
        *_data = *source._data;
        log("Deep-Copy Policy| Assignment Operator Call");
        return *this;
    }
    // 4. Move constructor
    deep(deep &&source){
        log("Deep-Copy Policy| Move Constructor Call");
        _data = source._data;
        source._data = nullptr;
    }
    // 5. Move assignment operator
    deep &operator=(deep &&source){
        log("Deep-Copy Policy| Move Assignment Operator Call");
        if (this == &source){return *this;}
        free(_data);
        _data = source._data;
        source._data = nullptr;
        return *this;
    }
    // 6. Destructor
    ~deep(){
        log("Deep-Copy Policy| Destructor Call");
        free(_data);
    }
    T* getdata(){
        return _data;
    }
};

// Shared-copying policy (unique_ptr)...
template<typename T>
class shared : public def<T> {
    using def<T>::log;
    using def<T>::_data;
private:
    static size_t _cnt;
public:
    // 0. Default constructor without initialization
    shared(){
        _data = (T *)malloc(sizeof(T));
        log("No-Copy Policy| Default Constructor Call");
    };
    // 1. Default constructor with initialization
    shared(T val){
        _data = (T *)malloc(sizeof(T));
        *_data = val;
        ++_cnt;
        log("Shared-Ownership Policy| Default Constructor Call with initialization");
        //std::cout << int(_cnt) << " shared copies" << std::endl;
    };
    // 2. Copy constructor
    shared(shared &source){
        _data = source._data;
        log("Shared-Ownership Policy| Copy Constructor Call");
        ++_cnt;
        //std::cout << int(_cnt) << " shared copies" << std::endl;
    };
    // 3. Assignment operator
    shared &operator=(shared &source){
        _data = source._data;
        log("Shared-Ownership Policy| Copy-Assignment Call");
        ++_cnt;
        //std::cout << int(_cnt) << " shared copies" << std::endl;
        return *this;
    }
    // 4. Move constructor
    shared(shared &&source){
        log("Shared-Copy Policy| Move Constructor Call");
        if (this == &source){return;}
        free(_data);
        --_cnt;
        //std::cout << int(_cnt) << " shared copies" << std::endl;
        _data = source._data;
        source._data = nullptr;
    }
    // 5. Move assignment operator
    shared &operator=(shared &&source){
        log("Shared-Copy Policy| Move Assignment Operator Call");
        if (this == &source){return *this;}
        free(_data);
        --_cnt;
        //std::cout << int(_cnt) << " shared copies" << std::endl;
        _data = source._data;
        source._data = nullptr;
        return *this;
    }
    // 6. Destructor
    ~shared(){
        log("Shared-Ownership Policy| Destructor Call");
        --_cnt;
        //std::cout << int(_cnt) << " shared copies" << std::endl;
        if (_cnt == 0){
            free(_data);
        }else{
        }
    };
    T* getdata(){
        return _data;
    }
};
template<typename T>
size_t shared<T>::_cnt = 0; // Initial set for counter for shared

}

int main(){

    struct Val{int _val[4]{1,2,3,4};}val; // Resource residing in stack

    copy::nocopy<Val> source1;
    {
        Val val1{1,2,3,4}; // Resource residing in stack
        source1 = val1;
    }
    std::cout << (source1.getdata()->_val[0]) << std::endl;

    {
        copy::nocopy<Val> source(val);
        copy::nocopy<Val> dest1(source);
        copy::nocopy<Val> dest2 = source;
        copy::nocopy<Val> dest3(std::move(dest1));
    }
    std::cout << std::endl;

    {
        copy::exclusive<Val> source(val);
        copy::exclusive<Val> dest1(source);
        copy::exclusive<Val> dest3(std::move(dest1));
    }
    std::cout << std::endl;

    {
        copy::deep<Val> source(val);
        copy::deep<Val> dest1(source);
        copy::deep<Val> dest2 = dest1;
        copy::deep<Val> dest3(std::move(dest1));
    }
    std::cout << std::endl;

    {
        copy::shared<Val> source(val);
        copy::shared<Val> dest1(source);
        copy::shared<Val> dest2 = source;
        dest2 = source;
        copy::shared<Val> dest3(val);
        dest3 = std::move(dest2);
    }

    return 0;
}