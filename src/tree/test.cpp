#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(InorderTraversalTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<int>{}, solution.inorderTraversal(nullptr));
}

TEST(InorderTraversalTest, one) {
  TreeNode root(1);
  Solution solution;
  EXPECT_EQ(vector<int>{root.val}, solution.inorderTraversal(&root));
}

TEST(InorderTraversalTest, one_level) {
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

TEST(InorderTraversalTest, all_left) {
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

TEST(InorderTraversalTest, all_right) {
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

TEST(InorderTraversalTest, complete_tree) {
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

TEST(KthSmallestTest, complete_tree) {
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
  for (int i = 1; i < 8; ++i) {
    EXPECT_EQ(i, solution.kthSmallest(&nodes.at(0), i));
  }
}

TEST(KthSmallestTest, invalid_k) {
  TreeNode root(1);
  Solution solution;

  EXPECT_THROW(solution.kthSmallest(nullptr, 1), std::range_error);
  EXPECT_THROW(solution.kthSmallest(&root, 0), std::range_error);
  EXPECT_THROW(solution.kthSmallest(&root, -1), std::range_error);
  EXPECT_THROW(solution.kthSmallest(&root, 2), std::range_error);
}

TEST(KthSmallestTest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(10000-i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  EXPECT_EQ(1, solution.kthSmallest(&nodes.at(0), 1));
  EXPECT_EQ(5000, solution.kthSmallest(&nodes.at(0), 5000));
  EXPECT_EQ(10000, solution.kthSmallest(&nodes.at(0), 10000));
}

TEST(KthSmallestTest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i+1);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  EXPECT_EQ(1, solution.kthSmallest(&nodes.at(0), 1));
  EXPECT_EQ(5000, solution.kthSmallest(&nodes.at(0), 5000));
  EXPECT_EQ(10000, solution.kthSmallest(&nodes.at(0), 10000));
}

TEST(LevelOrderTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<vector<int>>{}, solution.levelOrder(nullptr));
}

TEST(LevelOrderTest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  auto output = solution.levelOrder(&nodes.at(0));

  int level = 0;
  for (auto vec : output) {
    EXPECT_EQ(vector<int>{level++}, vec);
  }
}

TEST(LevelOrderTest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  auto output = solution.levelOrder(&nodes.at(0));

  int level = 0;
  for (auto vec : output) {
    EXPECT_EQ(vector<int>{level++}, vec);
  }
}

TEST(ZigZagLevelOrderTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<vector<int>>{}, solution.zigzagLevelOrder(nullptr));
}

TEST(ZigZagLevelOrderTest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  auto output = solution.zigzagLevelOrder(&nodes.at(0));

  int level = 0;
  for (auto vec : output) {
    EXPECT_EQ(vector<int>{level++}, vec);
  }
}

TEST(ZigZagLevelOrderTest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  auto output = solution.zigzagLevelOrder(&nodes.at(0));

  int level = 0;
  for (auto vec : output) {
    EXPECT_EQ(vector<int>{level++}, vec);
  }
}

TEST(ZigZagLevelOrderTest, complete_tree) {
  vector<TreeNode> nodes {
    TreeNode(1),
    TreeNode(3),
    TreeNode(2),
    TreeNode(4),
    TreeNode(5),
    TreeNode(6),
    TreeNode(7)
  };

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];

  Solution solution;
  auto output = solution.zigzagLevelOrder(&nodes.at(0));

  int val = 1;
  for (auto& vec : output) {
    for (auto v : vec) {
      EXPECT_EQ(val++, v);
    }
  }
}

TEST(ValidBSTTest, empty) {
  Solution solution;
  EXPECT_TRUE(solution.isValidBST(nullptr));
}

TEST(ValidBSTTest, limit) {
  vector<TreeNode> nodes {
    TreeNode(0),
    TreeNode(INT_MIN),
    TreeNode(INT_MAX),
  };

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];

  Solution solution;
  EXPECT_TRUE(solution.isValidBST(&nodes[0]));

  nodes[1].right = &nodes[0];
  nodes[0].left = nullptr;
  EXPECT_TRUE(solution.isValidBST(&nodes[1]));

  nodes[2].left = &nodes[0];
  nodes[0].right = nullptr;
  EXPECT_TRUE(solution.isValidBST(&nodes[1]));

  nodes[1].right = nullptr;
  nodes[0].left = &nodes[1];
  EXPECT_TRUE(solution.isValidBST(&nodes[2]));

  nodes[1].right = &nodes[0];
  nodes[0].left = nullptr;
  EXPECT_TRUE(solution.isValidBST(&nodes[2]));
}

TEST(ValidBSTTest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(10000-i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  EXPECT_TRUE(solution.isValidBST(&nodes.at(0)));

  TreeNode zero(0);
  for (int i = 0; i < 10000; ++i) {
    nodes[i].right = &zero;
    EXPECT_FALSE(solution.isValidBST(&nodes.at(0)));
    nodes[i].right = nullptr;
  }
}

TEST(ValidBSTTest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  EXPECT_TRUE(solution.isValidBST(&nodes.at(0)));

  TreeNode max(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes[i].left = &max;
    EXPECT_FALSE(solution.isValidBST(&nodes.at(0)));
    nodes[i].right = nullptr;
  }
}

TEST(ValidBSTTest, complete_tree) {
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
  EXPECT_TRUE(solution.isValidBST(&nodes.at(0)));
}

TEST(PopulateNextTest, empty) {
  Solution solution;
  EXPECT_NO_THROW(solution.connect(nullptr));
}

TEST(PopulateNextTest, complete_tree) {
  vector<TreeLinkNode> nodes {
    TreeLinkNode(0),
    TreeLinkNode(1),
    TreeLinkNode(2),
    TreeLinkNode(3),
    TreeLinkNode(4),
    TreeLinkNode(5),
    TreeLinkNode(6)
  };

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];

  Solution solution;
  solution.connect(&nodes.at(0));

  vector<TreeLinkNode*> level;
  level.push_back(&nodes[0]);

  while (!level.empty()) {
    vector<TreeLinkNode*> nextLevel;
    for (int i = 0; i < level.size(); ++i) {
      if (i != level.size()-1) {
        EXPECT_EQ(level[i+1], level[i]->next);
      } else {
        EXPECT_EQ(nullptr, level[i]->next);
      }
      if (level[i]->left) {
        nextLevel.push_back(level[i]->left);
      }
      if (level[i]->right) {
        nextLevel.push_back(level[i]->right);
      }
    }
    level.swap(nextLevel);
  }
}

TEST(LevelAverageTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<double>{}, solution.averageOfLevels(nullptr));
}

TEST(LevelAverageTest, complete_tree) {
  Solution solution;

  vector<TreeNode> nodes {
    TreeNode(0),
    TreeNode(1),
    TreeNode(1),
    TreeNode(2),
    TreeNode(2),
    TreeNode(2),
    TreeNode(2)
  };

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];

  EXPECT_EQ((vector<double>{0.0, 1.0, 2.0}), solution.averageOfLevels(&nodes.at(0)));
}

TEST(LevelAverageTest, all_left) {
  Solution solution;

  vector<TreeNode> nodes;
  nodes.reserve(10000);
  vector<double> expected;
  expected.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
    expected.emplace_back(i);
  }

  EXPECT_EQ(expected, solution.averageOfLevels(&nodes.at(0)));
}

TEST(LevelAverageTest, all_right) {
  Solution solution;

  vector<TreeNode> nodes;
  nodes.reserve(10000);
  vector<double> expected;
  expected.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
    expected.emplace_back(i);
  }

  EXPECT_EQ(expected, solution.averageOfLevels(&nodes.at(0)));
}

TEST(InvertTreeTest, empty) {
  Solution solution;

  EXPECT_EQ(nullptr, solution.invertTree(nullptr));
}

TEST(InvertTreeTest, one) {
  Solution solution;

  TreeNode node(0);
  EXPECT_EQ(&node, solution.invertTree(&node));
  EXPECT_EQ(nullptr, node.left);
  EXPECT_EQ(nullptr, node.right);
}

TEST(InvertTreeTest, all_left) {
  Solution solution;

  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  EXPECT_EQ(&nodes[0], solution.invertTree(&nodes.at(0)));
  for (int i = 1; i < 10000; ++i) {
    EXPECT_EQ(nullptr, nodes[i-1].left);
    EXPECT_EQ(&nodes[i], nodes[i-1].right);
  }
  EXPECT_EQ(nullptr, nodes.back().left);
  EXPECT_EQ(nullptr, nodes.back().right);
}

TEST(InvertTreeTest, all_right) {
  Solution solution;

  vector<TreeNode> nodes;
  nodes.reserve(10000);
  for (int i = 0; i < 10000; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  EXPECT_EQ(&nodes[0], solution.invertTree(&nodes.at(0)));
  for (int i = 1; i < 10000; ++i) {
    EXPECT_EQ(&nodes[i], nodes[i-1].left);
    EXPECT_EQ(nullptr, nodes[i-1].right);
  }
  EXPECT_EQ(nullptr, nodes.back().left);
  EXPECT_EQ(nullptr, nodes.back().right);
}

TEST(LCAinBSTTest, empty) {
  Solution solution;
  EXPECT_EQ(nullptr, solution.lowestCommonAncestorBST(nullptr, nullptr, nullptr));

  TreeNode n(0);
  EXPECT_EQ(nullptr, solution.lowestCommonAncestorBST(&n, nullptr, nullptr));
  EXPECT_EQ(nullptr, solution.lowestCommonAncestorBST(nullptr, &n, nullptr));
  EXPECT_EQ(nullptr, solution.lowestCommonAncestorBST(nullptr, nullptr, &n));
  EXPECT_EQ(nullptr, solution.lowestCommonAncestorBST(nullptr, &n, &n));
}

TEST(LCAinBSTTest, complete_tree) {
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
  EXPECT_EQ(&nodes.at(0), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(1), &nodes.at(2)));
  EXPECT_EQ(&nodes.at(0), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(3), &nodes.at(6)));
  EXPECT_EQ(&nodes.at(0), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(4), &nodes.at(5)));
  EXPECT_EQ(&nodes.at(1), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(4), &nodes.at(3)));
  EXPECT_EQ(&nodes.at(1), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(1), &nodes.at(4)));
  EXPECT_EQ(&nodes.at(2), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(5), &nodes.at(6)));
  EXPECT_EQ(&nodes.at(2), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(5), &nodes.at(2)));
}


TEST(LCAinBSTTest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(100);
  for (int i = 0; i < 100; ++i) {
    nodes.emplace_back(100-i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  for (int i = 0; i < 100; ++i) {
    for (int j = i; j < 100; ++j) {
      EXPECT_EQ(&nodes.at(i), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(i), &nodes.at(j)));
    }
  }
}

TEST(LCAinBSTTest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(100);
  for (int i = 0; i < 100; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  for (int i = 0; i < 100; ++i) {
    for (int j = i; j < 100; ++j) {
      EXPECT_EQ(&nodes.at(i), solution.lowestCommonAncestorBST(&nodes.at(0), &nodes.at(i), &nodes.at(j)));
    }
  }
}

TEST(LCATest, empty) {
  Solution solution;
  EXPECT_EQ(nullptr, solution.lowestCommonAncestor(nullptr, nullptr, nullptr));

  TreeNode n(0);
  EXPECT_EQ(nullptr, solution.lowestCommonAncestor(&n, nullptr, nullptr));
  EXPECT_EQ(nullptr, solution.lowestCommonAncestor(nullptr, &n, nullptr));
  EXPECT_EQ(nullptr, solution.lowestCommonAncestor(nullptr, nullptr, &n));
  EXPECT_EQ(nullptr, solution.lowestCommonAncestor(nullptr, &n, &n));
}

TEST(LCATest, complete_tree) {
  vector<TreeNode> nodes {
    TreeNode(0),
    TreeNode(1),
    TreeNode(2),
    TreeNode(3),
    TreeNode(4),
    TreeNode(5),
    TreeNode(6)
  };

  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[1].left = &nodes[3];
  nodes[1].right = &nodes[4];
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];

  Solution solution;
  EXPECT_EQ(&nodes.at(0), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(1), &nodes.at(2)));
  EXPECT_EQ(&nodes.at(0), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(3), &nodes.at(6)));
  EXPECT_EQ(&nodes.at(0), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(4), &nodes.at(5)));
  EXPECT_EQ(&nodes.at(1), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(4), &nodes.at(3)));
  EXPECT_EQ(&nodes.at(1), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(1), &nodes.at(4)));
  EXPECT_EQ(&nodes.at(2), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(5), &nodes.at(6)));
  EXPECT_EQ(&nodes.at(2), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(5), &nodes.at(2)));
}


TEST(LCATest, all_left) {
  vector<TreeNode> nodes;
  nodes.reserve(100);
  for (int i = 0; i < 100; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).left = &nodes.at(i);
    }
  }

  Solution solution;
  for (int i = 0; i < 100; ++i) {
    for (int j = i; j < 100; ++j) {
      EXPECT_EQ(&nodes.at(i), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(i), &nodes.at(j)));
    }
  }
}

TEST(LCATest, all_right) {
  vector<TreeNode> nodes;
  nodes.reserve(100);
  for (int i = 0; i < 100; ++i) {
    nodes.emplace_back(i);
    if (i > 0) {
      nodes.at(i-1).right = &nodes.at(i);
    }
  }

  Solution solution;
  for (int i = 0; i < 100; ++i) {
    for (int j = i; j < 100; ++j) {
      EXPECT_EQ(&nodes.at(i), solution.lowestCommonAncestor(&nodes.at(0), &nodes.at(i), &nodes.at(j)));
    }
  }
}

TEST(MergeBinaryTreeTest, empty) {
  Solution solution;

  EXPECT_EQ(nullptr, solution.mergeTrees(nullptr, nullptr));

  TreeNode node(1);
  EXPECT_EQ(&node, solution.mergeTrees(&node, nullptr));
  EXPECT_EQ(&node, solution.mergeTrees(nullptr, &node));
}

TEST(MergeBinaryTreeTest, small) {
  Solution solution;

  TreeNode t1(1);
  TreeNode t1_left(3);
  TreeNode t1_right(5);
  TreeNode t2(2);
  TreeNode t2_left(4);
  TreeNode t2_right(6);

  // t2
  auto root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(nullptr, root->left);
  EXPECT_EQ(nullptr, root->right);

  t1 = TreeNode(1);
  t1.left = &t1_left;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3, root->left->val);
  EXPECT_EQ(nullptr, root->right);

  t1 = TreeNode(1);
  t1.right= &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(nullptr, root->left);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5, root->right->val);

  t1_left = TreeNode(3);
  t1_right = TreeNode(5);
  t1 = TreeNode(1);
  t1.left = &t1_left;
  t1.right = &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3, root->left->val);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5, root->right->val);

  // t2->t2_left
  t1 = TreeNode(1);
  t2.left = &t2_left;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t2_left, root->left);
  EXPECT_EQ(4, root->left->val);
  EXPECT_EQ(nullptr, root->right);

  t1 = TreeNode(1);
  t1.left = &t1_left;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3+4, root->left->val);
  EXPECT_EQ(nullptr, root->right);

  t1 = TreeNode(1);
  t1.right= &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t2_left, root->left);
  EXPECT_EQ(4, root->left->val);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5, root->right->val);

  t1_left = TreeNode(3);
  t1_right = TreeNode(5);
  t1 = TreeNode(1);
  t1.left = &t1_left;
  t1.right = &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3+4, root->left->val);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5, root->right->val);

  // t2->t2_right
  t1 = TreeNode(1);
  t2.left = nullptr;
  t2.right = &t2_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(nullptr, root->left);
  EXPECT_EQ(&t2_right, root->right);
  EXPECT_EQ(6, root->right->val);

  t1_left = TreeNode(3);
  t1 = TreeNode(1);
  t1.left = &t1_left;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3, root->left->val);
  EXPECT_EQ(&t2_right, root->right);
  EXPECT_EQ(6, root->right->val);

  t1_right = TreeNode(5);
  t1 = TreeNode(1);
  t1.right= &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(nullptr, root->left);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5+6, root->right->val);

  t1_left = TreeNode(3);
  t1_right = TreeNode(5);
  t1 = TreeNode(1);
  t1.left = &t1_left;
  t1.right = &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3, root->left->val);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5+6, root->right->val);

  // t2->t2_left
  //   ->t2_right
  t1 = TreeNode(1);
  t2.left = &t2_left;
  t2.right = &t2_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t2_left, root->left);
  EXPECT_EQ(4, root->left->val);
  EXPECT_EQ(&t2_right, root->right);
  EXPECT_EQ(6, root->right->val);

  t1_left = TreeNode(3);
  t1 = TreeNode(1);
  t1.left = &t1_left;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3+4, root->left->val);
  EXPECT_EQ(&t2_right, root->right);
  EXPECT_EQ(6, root->right->val);

  t1_right = TreeNode(5);
  t1 = TreeNode(1);
  t1.right= &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t2_left, root->left);
  EXPECT_EQ(4, root->left->val);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5+6, root->right->val);

  t1_left = TreeNode(3);
  t1_right = TreeNode(5);
  t1 = TreeNode(1);
  t1.left = &t1_left;
  t1.right = &t1_right;
  root = solution.mergeTrees(&t1, &t2);
  EXPECT_EQ(1+2, root->val);
  EXPECT_EQ(&t1_left, root->left);
  EXPECT_EQ(3+4, root->left->val);
  EXPECT_EQ(&t1_right, root->right);
  EXPECT_EQ(5+6, root->right->val);
}

TEST(MaxPathSumTest, empty) {
  Solution solution;
  EXPECT_EQ(0, solution.maxPathSum(nullptr));
}

TEST(MaxPathSumTest, example) {
  Solution solution;

  TreeNode root(1);
  EXPECT_EQ(1, solution.maxPathSum(&root));

  root.val = -1;
  EXPECT_EQ(-1, solution.maxPathSum(&root));

  TreeNode l(1);
  root.left = &l;
  EXPECT_EQ(1, solution.maxPathSum(&root));

  l.val = -1;
  EXPECT_EQ(-1, solution.maxPathSum(&root));

  TreeNode r(1);
  root.right = &r;
  EXPECT_EQ(1, solution.maxPathSum(&root));

  r.val = -1;
  EXPECT_EQ(-1, solution.maxPathSum(&root));

  l.val = 1;
  r.val = 1;
  EXPECT_EQ(1, solution.maxPathSum(&root));

  root.val = 1;
  EXPECT_EQ(3, solution.maxPathSum(&root));

  TreeNode ll(3);
  l.left = &ll;
  EXPECT_EQ(6, solution.maxPathSum(&root));

  TreeNode lr(3);
  l.right = &lr;
  EXPECT_EQ(7, solution.maxPathSum(&root));

  TreeNode rl(2);
  r.left = &rl;
  EXPECT_EQ(8, solution.maxPathSum(&root));

  TreeNode rr(10);
  r.right = &rr;
  EXPECT_EQ(16, solution.maxPathSum(&root));

  r.val = -6;
  EXPECT_EQ(10, solution.maxPathSum(&root));

  rl.val = 10;
  EXPECT_EQ(14, solution.maxPathSum(&root));
}

TEST(SearchBSTTest, example) {
  Solution solution;

  EXPECT_EQ(nullptr, solution.searchBST(nullptr, 0));

  vector<TreeNode> nodes;
  nodes.reserve(100);
  for (int i = 0; i < 100; ++i) {
    nodes.emplace_back(-2*i);
    if (i > 0) {
      nodes[i-1].left = &nodes[i];
    }
  }

  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(&nodes.at(i), solution.searchBST(&nodes.at(0), -2*i));
    EXPECT_EQ(nullptr, solution.searchBST(&nodes.at(0), -2*i - 1));
  }

  for (int i = 0; i < 100; ++i) {
    nodes[i].val *= -1;
    if (i > 0) {
      nodes[i-1].right = &nodes[i];
      nodes[i-1].left = nullptr;
    }
  }

  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(&nodes.at(i), solution.searchBST(&nodes.at(0), 2*i));
    EXPECT_EQ(nullptr, solution.searchBST(&nodes.at(0), 2*i + 1));
  }
}

TEST(UnivaluePathTest, example) {
  Solution solution;

  EXPECT_EQ(0, solution.longestUnivaluePath(nullptr));

  TreeNode root(1);
  EXPECT_EQ(0, solution.longestUnivaluePath(&root));

  TreeNode l(0);
  root.left = &l;
  EXPECT_EQ(0, solution.longestUnivaluePath(&root));

  l.val = 1;
  EXPECT_EQ(1, solution.longestUnivaluePath(&root));

  TreeNode r(0);
  root.right = &r;
  EXPECT_EQ(1, solution.longestUnivaluePath(&root));

  r.val = 1;
  EXPECT_EQ(2, solution.longestUnivaluePath(&root));

  l.val = 0;
  EXPECT_EQ(1, solution.longestUnivaluePath(&root));

  root.left = nullptr;
  EXPECT_EQ(1, solution.longestUnivaluePath(&root));

  vector<TreeNode> zeros(100, {0});
  for (int i = 1; i < zeros.size(); ++i) {
    zeros[i-1].left = &zeros[i];
  }
  root.left = &zeros[0];
  EXPECT_EQ(99, solution.longestUnivaluePath(&root));
  root.right = &zeros[0];
  EXPECT_EQ(99, solution.longestUnivaluePath(&root));

  vector<TreeNode> ones(100, {1});
  for (int i = 1; i < ones.size(); ++i) {
    ones[i-1].right = &ones[i];
  }
  root.left = &ones[0];
  EXPECT_EQ(100, solution.longestUnivaluePath(&root));
  root.right = &ones[0];
  EXPECT_EQ(200, solution.longestUnivaluePath(&root));
}

}
