import <iostream>;
import <string>;
import <cmath>;
import mainmodule;

//#include <fmt/core.h>

int main(int argc, char **argv){

  namespace wewe = hello::carlos;

  for (int i = 1; i < argc; ++i){
    std::string n_ = argv[i];
    int n = std::stoi(n_);
    std::cout << n << std::endl;
    
    class wewe::Hello hello = wewe::Hello();
    
    for(int j = 0; j < n; j++){
      hello.say();
    }
  }
  return 0;
}
