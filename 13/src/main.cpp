import <iostream>;
import mainmodule;

int main() {
  {
    enum fruits::Fruit i = fruits::Fruit::banana; // decltype(i) == enum Fruit
    std::cout << static_cast<int>(i) << std::endl; // 1
    i = fruits::Fruit::orange;
    std::cout << static_cast<int>(i) << std::endl; // 3

    enum fruits::Citrus j = fruits::Citrus::grapefruit;

    using enum fruits::Citrus;

    j = orange;

    std::cout << static_cast<int>(j) << std::endl; // 3
  }

  std::cout << "Everything is ok..." << std::endl;
}