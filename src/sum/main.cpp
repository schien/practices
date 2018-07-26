#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  std::vector<int> A = next_vector<int>();
  std::vector<int> B = next_vector<int>();
  std::vector<int> C = next_vector<int>();
  std::vector<int> D = next_vector<int>();

  Solution solution;

  auto output = solution.fourSumCount(A,B,C,D);
  std::cout << output << std::endl;
  return 0;
}
