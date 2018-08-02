#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  Solution solution;
  std::vector<int> coins = next_vector<int>();
  int amount = next<int>();

  auto output = solution.coinChange(coins, amount);

  std::cout << output << std::endl;
  return 0;
}
