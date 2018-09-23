#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: heaters n house_1 ... house_n m heater_1 ... heater_m\n"
            << std::flush;
}

int main() {
  Solution solution;
  vector<int> houses = next_vector<int>();
  vector<int> heaters = next_vector<int>();
  auto output = solution.findRadius(houses, heaters);
  std::cout << output << std::endl;
  return 0;
}
