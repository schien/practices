#include <iostream>

#include "solution.cpp"

void usage() {
  std::cout << "[usage] {base} {n}" << std::endl;
  exit(1);
}

int main() {
  int base;
  std::cin >> base;

  int n;
  std::cin >> n;

  Solution solution;

  bool output;
  switch (base) {
    case 2:
      output = solution.isPowerOfTwo(n);
      break;
    case 3:
      output = solution.isPowerOfThree(n);
      break;
    default:
      usage();
  }

  std::cout << output << std::endl;

  return 0;
}
