#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(MinHeightTreesTest, example) {
  Solution solution;

  vector<pair<int,int>> edges;
  EXPECT_EQ(vector<int>{0}, solution.findMinHeightTrees(1, edges));

  edges = {{0,1}};
  EXPECT_EQ((vector<int>{0,1}), solution.findMinHeightTrees(2, edges));

  edges = {{0,1},{0,2}};
  EXPECT_EQ((vector<int>{0}), solution.findMinHeightTrees(3, edges));

  edges = {{1,0},{1,2},{1,3}};
  EXPECT_EQ((vector<int>{1}), solution.findMinHeightTrees(4, edges));

  edges = {{0,3},{1,3},{2,3},{4,3},{5,4}};
  EXPECT_EQ((vector<int>{3,4}), solution.findMinHeightTrees(6, edges));

  edges.resize(10000);
  for (int i = 0; i < 10000; ++i) {
    edges[i] = {i, i+1};
  }
  EXPECT_EQ((vector<int>{5000}), solution.findMinHeightTrees(10001, edges));

  edges.emplace_back(10000, 10001);
  EXPECT_EQ((vector<int>{5000,5001}), solution.findMinHeightTrees(10002, edges));
}

}
