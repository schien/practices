#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  std::vector<int> gas = next_vector<int>();
  std::vector<int> cost = next_vector<int>();

  Solution solution;
  auto output = solution.canCompleteCircuit(gas, cost);
  std::cout << output << std::endl;
  return 0;
}
