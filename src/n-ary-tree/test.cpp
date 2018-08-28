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

}
