#include <iostream>
#include <vector>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  std::vector<int> input = next<std::vector<int>>();
  Solution solution;
  auto output = solution.rob(input);
  std::cout << output << std::endl;
  return 0;
}
