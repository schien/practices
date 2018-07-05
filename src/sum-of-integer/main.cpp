#include <iostream>

#include "solution.cpp"

int main() {
  int a, b;
  std::cin >> a >> b;

  Solution solution;
  auto output = solution.getSum(a, b);

  std::cout << output << std::endl;

  return 0;
}
