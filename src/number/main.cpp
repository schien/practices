#include <iostream>

#include "solution.cpp"

int main() {
  int n;
  std::cin >> n;

  Solution solution;
  auto happy = solution.isHappy(n);
  auto digit = solution.addDigits(n);

  std::cout << "happy: " << happy << std::endl;
  std::cout << "digit: " << digit << std::endl;

  return 0;
}
