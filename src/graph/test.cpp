#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(BipartiteTest, example) {
  Solution solution;

  vector<vector<int>> graph;
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{},{}};
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{1},{0}};
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{1},{0,2},{1}};
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{1,2},{0,2},{0,1}};
  EXPECT_FALSE(solution.isBipartite(graph));

  graph = {{1},{0},{3},{2}};
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{1,2},{0},{3,0},{2}};
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{1,2},{0,3},{3,0},{2,1}};
  EXPECT_TRUE(solution.isBipartite(graph));

  graph = {{1,2,3},{0},{3,0},{2,0}};
  EXPECT_FALSE(solution.isBipartite(graph));

  graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
  EXPECT_FALSE(solution.isBipartite(graph));

  graph = vector<vector<int>>(100);
  for (int i = 0; i < 50; ++i) {
    graph[i].emplace_back(i+50);
    graph[i+50].emplace_back(i);
  }
  EXPECT_TRUE(solution.isBipartite(graph));

  graph[0].emplace_back(49);
  graph[49].emplace_back(0);
  graph[0].emplace_back(99);
  graph[99].emplace_back(0);
  EXPECT_FALSE(solution.isBipartite(graph));
}

}
