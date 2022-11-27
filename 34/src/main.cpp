#include <iostream>
#include <vector>

namespace Sequences{

template <std::size_t Id>
class Fibonacci{
public:
    Fibonacci(std::size_t m1 = 1, std::size_t m2 = 0, std::size_t cnt = Id) : m1(m1), m2(m2), m0(m1 + m2), cnt(cnt){
        if (this->quest()){
            Fibonacci* fib{new Fibonacci<Id>(m0, m1, cnt-1)};
            delete fib;
        }
    };
    ~Fibonacci(){};
    bool quest(){
        if(cnt < 3){
            switch (cnt){
            case 2:
                std::cout << "The fibonacci number is " << m0 << std::endl;
                break;
            case 1:
                std::cout << "The fibonacci number is " << m1 << std::endl;
                break;
            default:
                std::cout << "The fibonacci number is " << m2 << std::endl;
                break;
            }
            return false;
        } else {
            return true;
        }
    };

    private:
    std::size_t cnt;
    std::size_t m0;
    std::size_t m1;
    std::size_t m2;
};
}

namespace PrimeNumber{

template <std::size_t Id>
class Get{
public:
    Get(std::vector<std::size_t> primes = {{1}}, std::size_t cnt = Id+1) : primes(primes), cnt(cnt){
        if (this->quest()){
            Get* get{new Get<Id>(this->primes, cnt-1)};
            delete get;
        }
    };
    ~Get(){};
    bool quest(){
        if(cnt < 1){
            std::cout << "The prime number is " << primes.back() << std::endl;
            return false;
        } else {
            std::size_t next_prime = primes.back() + 1;
            do {
                bool go_up{false};
                for(std::size_t elem : primes){
                    if(elem == 1) continue;
                    if(next_prime%elem == 0){
                        go_up = true;
                        break;
                    }
                }
                if(go_up){
                    next_prime += 1;
                } else {
                    primes.push_back(next_prime);
                }
            } while (primes.back() != next_prime);
            return true;
        }
    };

    private:
    std::size_t cnt;
    std::vector<std::size_t> primes;
};
}

int main(){
    Sequences::Fibonacci<40'000>();
    PrimeNumber::Get<40'000>();
}