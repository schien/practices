#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  MedianFinder finder;
  while (true) {
    char op;
    std::cin >> op;
    if (std::cin.eof()) {
      break;
    }
    switch (op) {
      case 'a':
        finder.addNum(next<int>());
        break;
      case 'm':
        std::cout << finder.findMedian() << std::endl;
        break;
    }
  }
  return 0;
}
