#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  Solution solution;

  while(1) {
    int i, j;
    std::cin >> i >> j;
    if (std::cin.eof()) {
      break;
    }

    std::cout << i << ' ' << j << ' ' << solution.maxCycle(i, j) << '\n';
  }
  return 0;
}
