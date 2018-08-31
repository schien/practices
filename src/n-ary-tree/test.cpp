#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(PreorderTest, empty) {
  Solution solution;
  EXPECT_EQ((vector<int>{}), solution.preorder(nullptr));
}

TEST(PreorderTest, example) {
  Solution solution;
  vector<Node> nodes(11);
  for (int i = 0; i < 11; ++i) {
    nodes[i].val = i;
  }
  nodes[0].children.assign({&nodes[1], &nodes[2], &nodes[3], &nodes[4]});
  nodes[1].children.assign({&nodes[5], &nodes[6], &nodes[7]});
  nodes[2].children.assign({&nodes[8], &nodes[9]});
  nodes[3].children.assign({&nodes[10]});

  EXPECT_EQ((vector<int>{0, 1, 5, 6, 7, 2, 8, 9, 3, 10, 4}), solution.preorder(&nodes[0]));
}

TEST(LevelOrderTest, empty) {
  Solution solution;
  EXPECT_EQ((vector<vector<int>>{}), solution.levelOrder(nullptr));
}

TEST(LevelOrderTest, example) {
  Solution solution;
  vector<Node> nodes(11);
  for (int i = 0; i < 11; ++i) {
    nodes[i].val = i;
  }
  nodes[0].children.assign({&nodes[1], &nodes[2], &nodes[3], &nodes[4]});
  nodes[1].children.assign({&nodes[5], &nodes[6], &nodes[7]});
  nodes[2].children.assign({&nodes[8], &nodes[9]});
  nodes[3].children.assign({&nodes[10]});

  EXPECT_EQ((vector<vector<int>>{
    {0},
    {1,2,3,4},
    {5,6,7,8,9,10},
  }), solution.levelOrder(&nodes[0]));
}

TEST(PostorderTest, empty) {
  Solution solution;
  EXPECT_EQ((vector<int>{}), solution.postorder(nullptr));
}

TEST(PostorderTest, example) {
  Solution solution;
  vector<Node> nodes(11);
  for (int i = 0; i < 11; ++i) {
    nodes[i].val = i;
  }
  nodes[0].children.assign({&nodes[1], &nodes[2], &nodes[3], &nodes[4]});
  nodes[1].children.assign({&nodes[5], &nodes[6], &nodes[7]});
  nodes[2].children.assign({&nodes[8], &nodes[9]});
  nodes[3].children.assign({&nodes[10]});

  EXPECT_EQ((vector<int>{5, 6, 7, 1, 8, 9, 2, 10, 3, 4, 0}), solution.postorder(&nodes[0]));
}

TEST(MaxDepthTest, empty) {
  Solution solution;
  EXPECT_EQ(0, solution.maxDepth(nullptr));
}

TEST(MaxDepthTest, example) {
  Solution solution;
  vector<Node> nodes(11);
  for (int i = 0; i < 11; ++i) {
    nodes[i].val = i;
  }
  nodes[0].children.assign({&nodes[1], &nodes[2], &nodes[3], &nodes[4]});
  nodes[1].children.assign({&nodes[5], &nodes[6], &nodes[7]});
  nodes[2].children.assign({&nodes[8], &nodes[9]});
  nodes[3].children.assign({&nodes[10]});

  EXPECT_EQ(3, solution.maxDepth(&nodes[0]));
}

}
