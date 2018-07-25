#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  RandomizedSet rset;
  while (std::cin.good()) {
    char op;
    std::cin >> op;
    if (std::cin.eof()) {
      break;
    }

    switch (op) {
      case 'i':
        {
          std::cout << std::boolalpha << rset.insert(next<int>()) << '\n';
          break;
        }
      case 'd':
        {
          std::cout << std::boolalpha << rset.remove(next<int>()) << '\n';
          break;
        }
      case 'r':
        {
          try {
            std::cout << rset.getRandom() << '\n';
          } catch (runtime_error& ex) {
            std::cerr << ex.what() << std::endl;
          }
          break;
        }
      default:
        break;
    }
  }
  return 0;
}
