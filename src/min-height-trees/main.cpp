#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

vector<pair<int,int>> read_edges() {
  int k = next<int>();
  vector<pair<int,int>> result;
  for (int i = 0; i < k; ++i) {
    result.emplace_back(next<int>(), next<int>());
  }
  return result;
}

int main() {
  Solution solution;

  int n = next<int>();
  auto edges = read_edges();
  auto output = solution.findMinHeightTrees(n, edges);
  for (auto i : output) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
