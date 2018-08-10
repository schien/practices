#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  int n = next<int>();
  vector<pair<int, int>> prerequisites;
  for (int i = 0; i < n; ++i) {
    auto d = next_vector<int>();
    for (int n : d) {
      prerequisites.emplace_back(i, n);
    }
  }
  Solution solution;
  auto output = solution.canFinish(n, prerequisites);
  auto order = solution.findOrder(n, prerequisites);

  std::cout << std::boolalpha << output << std::endl;
  for (auto n: order) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
  return 0;
}
