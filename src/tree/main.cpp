#include <iostream>
#include <tuple>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage]: tree t n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              k n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << std::flush;
}

std::vector<TreeNode> tree_from_input(std::vector<std::tuple<int, int, int>>& input) {
  const int sz = input.size();

  std::vector<TreeNode> nodes(sz, TreeNode(0));

  for (int i = 0; i< sz; ++i) {
    auto& node = nodes[i];
    int val, left, right;
    std::tie(val, left, right) = input[i];
    node.val = val;
    if (left > 0) {
      nodes[i].left = &nodes.at(left);
    }
    if (right > 0) {
      nodes[i].right = &nodes.at(right);
    }
  }

  return nodes;
}

void runInorderTraversal() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeNode> nodes = tree_from_input(input);

  Solution solution;
  auto output = solution.inorderTraversal(&nodes.at(0));

  for (auto v : output) {
    std::cout << v << ' ';
  }
  std::cout << endl;
}

void runKthSmallest() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeNode> nodes = tree_from_input(input);

  int k = next<int>();

  Solution solution;
  try {
    auto output = solution.kthSmallest(&nodes.at(0), k);
    std::cout << output << '\n';
  } catch(std::range_error ex) {
    std::cerr << ex.what() << '\n';
  }
}

int main() {
  char op = next<char>();

  switch (op) {
    case 't':
      runInorderTraversal();
      break;
    case 'k':
      runKthSmallest();
      break;
    default:
      usage();
  }

  return 0;
}
