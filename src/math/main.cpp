#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: math p x n\n"
            << std::flush;
}

void runPowOfN() {
  double x = next<double>();
  int n = next<int>();

  Solution solution;
  auto output = solution.myPow(x, n);

  std::cout << output << std::endl;
}

int main() {
  char op = next<char>();

  switch(op) {
    case 'p':
      runPowOfN();
      break;
    default:
      usage();
      break;
  }
  return 0;
}
