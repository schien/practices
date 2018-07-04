#include <iostream>

#include "solution.cpp"

int main() {
  int n;
  std::cin >> n;

  Solution solution;
  auto output = solution.isPowerOfThree(n);

  std::cout << output << std::endl;

  return 0;
}
