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

}
