#include <iostream>

#include "solution.cpp"

int main() {
  int n;
  std::cin >> n;

  Solution solution;
  auto happy = solution.isHappy(n);
  auto digit = solution.addDigits(n);
  auto ugly = solution.isUgly(n);
  auto numSquares = solution.numSquares(n);

  std::cout << "happy: " << happy << std::endl;
  std::cout << "digit: " << digit << std::endl;
  std::cout << "ugly: " << ugly << std::endl;
  std::cout << "numSquares: " << numSquares << std::endl;

  int y;
  std::cin >> y;
  auto hammingDistance = solution.hammingDistance(n, y);
  std::cout << "hammingDistance: " << hammingDistance << std::endl;

  return 0;
}
