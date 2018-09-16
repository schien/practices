#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: math p x n\n"
            << "            d l r\n"
            << "            n x\n"
            << std::flush;
}

void runPowOfN() {
  double x = next<double>();
  int n = next<int>();

  Solution solution;
  auto output = solution.myPow(x, n);

  std::cout << output << std::endl;
}

void runSelfDividingNumbers() {
  Solution solution;
  auto output = solution.selfDividingNumbers(next<int>(), next<int>());

  for (auto n : output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runNthDigit() {
  Solution solution;
  auto output = solution.findNthDigit(next<int>());
  std::cout << output << std::endl;
}

int main() {
  char op = next<char>();

  switch(op) {
    case 'p':
      runPowOfN();
      break;
    case 'd':
      runSelfDividingNumbers();
      break;
    case 'n':
      runNthDigit();
      break;
    default:
      usage();
      break;
  }
  return 0;
}
