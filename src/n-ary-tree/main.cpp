#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage]: n-ary-tree p n v_1 k_1 c_1_1 ... c_1_k ... v_n k_n c_n_1 ... c_n_k\n"
            << "                    l n v_1 k_1 c_1_1 ... c_1_k ... v_n k_n c_n_1 ... c_n_k\n"
            << std::flush;
}

std::vector<Node> build_tree() {
  int n = next<int>();
  std::vector<Node> nodes(n);

  for (int i = 0; i < n; ++i) {
    nodes[i].val = next<int>();
    int k = next<int>();
    for (int j = 0; j < k; ++j) {
      nodes[i].children.emplace_back(&nodes.at(next<int>()));
    }
  }

  return nodes;
}

void runPreorder() {
  Solution solution;
  std::vector<Node> nodes = build_tree();

  auto output = solution.preorder(&nodes.at(0));
  for (auto n:output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runLevelOrder() {
  Solution solution;
  std::vector<Node> nodes = build_tree();

  auto output = solution.levelOrder(&nodes.at(0));
  for (auto vec:output) {
    for (auto n:vec) {
      std::cout << n << ' ';
    }
    std::cout << '\n';
  }
  std::cout.flush();
}

int main() {
  char op = next<char>();

  switch (op) {
    case 'p':
      runPreorder();
      break;
    case 'l':
      runLevelOrder();
      break;
    default:
      usage();
  }
  return 0;
}
