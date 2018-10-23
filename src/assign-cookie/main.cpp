#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  std::vector<int> g = next_vector<int>();
  std::vector<int> s = next_vector<int>();

  Solution solution;
  auto output = solution.findContentChildren(g, s);

  std::cout << output << std::endl;

  return 0;
}
