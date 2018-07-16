#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  std::vector<int> A = next();
  std::vector<int> B = next();
  std::vector<int> C = next();
  std::vector<int> D = next();

  Solution solution;

  auto output = solution.fourSumCount(A,B,C,D);
  std::cout << output << std::endl;
  return 0;
}
