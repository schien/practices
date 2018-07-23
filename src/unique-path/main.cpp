#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  int m = next<int>();
  int n = next<int>();

  Solution solution;
  auto output = solution.uniquePaths(m, n);
  std::cout << output << '\n';
  return 0;
}
