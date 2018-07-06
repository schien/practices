#include <iostream>

#include "solution.cpp"

int main() {
  int n;
  std::cin >> n;

  Solution solution;
  auto happy = solution.isHappy(n);
  auto digit = solution.addDigits(n);
  auto ugly = solution.isUgly(n);

  std::cout << "happy: " << happy << std::endl;
  std::cout << "digit: " << digit << std::endl;
  std::cout << "ugly: " << ugly << std::endl;

  return 0;
}
