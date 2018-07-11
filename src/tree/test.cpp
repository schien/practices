#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(TreeTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<int>{}, solution.inorderTraversal(nullptr));
}

TEST(TreeTest, one) {
  TreeNode root(1);
  Solution solution;
  EXPECT_EQ(vector<int>{root.val}, solution.inorderTraversal(&root));
}

TEST(TreeTest, one_level) {
  //   1
  //  / \
  // 2   3
  TreeNode nodes[3] = {
    TreeNode(1),
    TreeNode(2),
    TreeNode(3),
  };
  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];

  Solution solution;
  vector<int> expected = { nodes[1].val, nodes[0].val, nodes[2].val };
  EXPECT_EQ(expected, solution.inorderTraversal(&nodes[0]));
}

TEST(TreeTest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  vector<int> expected;
  expected.reserve(1000000);
  for (int i = 1000000-1; i >= 0; --i) {
    expected.push_back(i);
  }
  EXPECT_EQ(expected, solution.inorderTraversal(&nodes.at(0)));
}

TEST(TreeTest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  vector<int> expected;
  expected.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    expected.push_back(i);
  }
  EXPECT_EQ(expected, solution.inorderTraversal(&nodes.at(0)));
}

TEST(TreeTest, complete_tree) {
  vector<TreeNode> nodes {
    TreeNode(4),
    TreeNode(2),
    TreeNode(6),
    TreeNode(1),
    TreeNode(3),
    TreeNode(5),
    TreeNode(7)
  };

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];

  Solution solution;
  vector<int> expected;
  for (int i = 1; i < 8; ++i) {
    expected.push_back(i);
  }
  EXPECT_EQ(expected, solution.inorderTraversal(&nodes.at(0)));
}

}
