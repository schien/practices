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
  auto perfectSquare = solution.isPerfectSquare(n);
  auto squareSum= solution.judgeSquareSum(n);
  auto perfectNumber = solution.checkPerfectNumber(n);

  std::cout << "happy: " << happy << std::endl;
  std::cout << "digit: " << digit << std::endl;
  std::cout << "ugly: " << ugly << std::endl;
  std::cout << "numSquares: " << numSquares << std::endl;
  std::cout << "isPerfectSquare: " << perfectSquare << std::endl;
  std::cout << "judgeSquareSum:" << squareSum << std::endl;
  std::cout << "checkPerfectNumber:" << perfectNumber << std::endl;

  int y;
  std::cin >> y;
  auto hammingDistance = solution.hammingDistance(n, y);
  std::cout << "hammingDistance: " << hammingDistance << std::endl;

  return 0;
}
