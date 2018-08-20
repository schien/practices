#include <iostream>
#include <tuple>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage]: tree t n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              k n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              l n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              z n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              v n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              n n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << "              a n t1_v t1_left t1_right ... tn_v tn_left tn_right\n"
            << std::flush;
}

template<typename NodeType>
std::vector<NodeType> tree_from_input(std::vector<std::tuple<int, int, int>>& input) {
  const int sz = input.size();

  std::vector<NodeType> nodes(sz, NodeType(0));

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

  std::vector<TreeNode> nodes = tree_from_input<TreeNode>(input);

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

  std::vector<TreeNode> nodes = tree_from_input<TreeNode>(input);

  int k = next<int>();

  Solution solution;
  try {
    auto output = solution.kthSmallest(&nodes.at(0), k);
    std::cout << output << '\n';
  } catch(std::range_error ex) {
    std::cerr << ex.what() << '\n';
  }
}

void runLevelOrder() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeNode> nodes = tree_from_input<TreeNode>(input);

  Solution solution;
  auto output = solution.levelOrder(&nodes.at(0));
  for (auto vec : output) {
    for (auto v : vec) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
  }
}

void runZigZagLevelOrder() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeNode> nodes = tree_from_input<TreeNode>(input);

  Solution solution;
  auto output = solution.zigzagLevelOrder(&nodes.at(0));
  for (auto vec : output) {
    for (auto v : vec) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
  }
}

void runValidBST() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeNode> nodes = tree_from_input<TreeNode>(input);

  Solution solution;
  auto output = solution.isValidBST(&nodes.at(0));
  std::cout << std::boolalpha << output << std::endl;
}

void runPopulateNext() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeLinkNode> nodes = tree_from_input<TreeLinkNode>(input);

  Solution solution;
  solution.connect(&nodes.at(0));

  std::vector<TreeLinkNode*> q;
  q.push_back(&nodes.at(0));
  int i = 0;
  while (i < q.size()) {
    auto node = q[i++];
    std::cout << node->val << '(';

    if (node->left) {
      q.push_back(node->left);
      std::cout << node->left->val;
    } else {
      std::cout << '#';
    }
    std::cout << ',';

    if (node->right) {
      q.push_back(node->right);
      std::cout << node->right->val;
    } else {
      std::cout << '#';
    }
    std::cout << ',';

    if (node->next) {
      std::cout << node->next->val;
    } else {
      std::cout << '#';
    }

    std::cout << ')' << '\n';
  }
  std::cout << std::flush;
}

void runLevelAverage() {
  int n = next<int>();
  std::vector<tuple<int, int, int>> input;

  for (int i = 0; i < n; ++i) {
    int v = next<int>(), l = next<int>(), r = next<int>();
    input.emplace_back(v,l,r);
  }

  std::vector<TreeNode> nodes = tree_from_input<TreeNode>(input);

  Solution solution;
  auto output = solution.averageOfLevels(&nodes.at(0));
  for (auto v : output) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;
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
    case 'l':
      runLevelOrder();
      break;
    case 'z':
      runZigZagLevelOrder();
      break;
    case 'v':
      runValidBST();
      break;
    case 'n':
      runPopulateNext();
      break;
    case 'a':
      runLevelAverage();
      break;
    default:
      usage();
  }

  return 0;
}
