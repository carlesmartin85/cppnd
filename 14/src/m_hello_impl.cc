export module mainmodule:hello;

import <iostream>;

export namespace hello::carlos{

  class Hello{
  public:
    Hello() : cnt_(0){};
    void say(){
      ++cnt_;
      std::cout << "Hi " << cnt_ << "!" << std::endl;
    };

  private:
    int cnt_{};
  };
};