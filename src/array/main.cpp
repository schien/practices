#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void output_vector(vector<int>& vec) {
  for (auto n : vec) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> num1 = next();
  std::vector<int> num2 = next();

  Solution solution;
  auto output = solution.intersection(num1, num2);
  output_vector(output);

  output = solution.intersect(num1, num2);
  output_vector(output);

  return 0;
}
