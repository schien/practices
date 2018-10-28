#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  Solution solution;

  std::vector<std::string> ops = next_vector<std::string>();
  auto output = solution.calPoints(ops);
  std::cout << output << std::endl;

  return 0;
}
