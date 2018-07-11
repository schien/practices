#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  std::vector<int> node_vals = next();

  std::vector<TreeNode> nodes;
  for (auto val : node_vals) {
    nodes.emplace_back(val);
  }

  for (int i = 0; i< nodes.size(); ++i) {
    int left = next<int>();
    if (left > 0) {
      nodes[i].left = &nodes.at(left);
    }
    int right = next<int>();
    if (right > 0) {
      nodes[i].right = &nodes.at(right);
    }
  }

  Solution solution;
  auto output = solution.inorderTraversal(&nodes.at(0));

  for (auto v : output) {
    std::cout << v << ' ';
  }
  std::cout << endl;
  return 0;
}
