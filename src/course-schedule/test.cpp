#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

bool verifyOrder(vector<int>& order, vector<pair<int,int>>& prerequisites) {
  vector<bool> traversed(order.size());
  vector<vector<int>> dep(order.size());
  for (auto& p:prerequisites) {
    dep[p.first].emplace_back(p.second);
  }
  for (int i = 0; i < order.size(); ++i) {
    if (traversed[order[i]]) {
      return false;
    }
    for (auto d:dep[order[i]]) {
      if (!traversed[d]) {
        return false;
      }
    }
    traversed[order[i]] = true;
  }
  return true;
}

TEST(CourseScheduleTest, empty) {
  Solution solution;
  vector<pair<int,int>> prerequisites;
  EXPECT_TRUE(solution.canFinish(0, prerequisites));
  EXPECT_EQ(vector<int>{}, solution.findOrder(0, prerequisites));
}

TEST(CourseScheduleTest, one) {
  Solution solution;
  vector<pair<int,int>> prerequisites;
  EXPECT_TRUE(solution.canFinish(1, prerequisites));
  EXPECT_EQ(vector<int>{0}, solution.findOrder(1, prerequisites));

  prerequisites.emplace_back(0, 0);
  EXPECT_FALSE(solution.canFinish(1, prerequisites));
  EXPECT_EQ(vector<int>{}, solution.findOrder(1, prerequisites));
}

TEST(CourseScheduleTest, small) {
  Solution solution;
  int n = 10;
  vector<pair<int,int>> prerequisites;
  EXPECT_TRUE(solution.canFinish(n, prerequisites));
  auto order = solution.findOrder(n, prerequisites);
  EXPECT_TRUE(verifyOrder(order, prerequisites));

  for (int i = 0; i < n-1; ++i) {
    prerequisites.emplace_back(i, i+1);
  }
  EXPECT_TRUE(solution.canFinish(n, prerequisites));
  order = solution.findOrder(n, prerequisites);
  EXPECT_TRUE(verifyOrder(order, prerequisites));

  prerequisites.emplace_back(n-1, 0);
  EXPECT_FALSE(solution.canFinish(n, prerequisites));
  EXPECT_EQ((vector<int>{}), solution.findOrder(n, prerequisites));

  prerequisites.pop_back();
  for (int i = 0; i < n-1; ++i) {
    prerequisites.emplace_back(i+1+n, i+n);
  }
  EXPECT_TRUE(solution.canFinish(n+n, prerequisites));
  order = solution.findOrder(n+n, prerequisites);
  EXPECT_TRUE(verifyOrder(order, prerequisites));

  prerequisites.emplace_back(n, n+n-1);
  EXPECT_FALSE(solution.canFinish(n+n, prerequisites));
  EXPECT_EQ((vector<int>{}), solution.findOrder(n+n, prerequisites));
}

TEST(CourseScheduleTest, large) {
  Solution solution;
  int n = 1 << 20;
  vector<pair<int,int>> prerequisites;
  EXPECT_TRUE(solution.canFinish(n, prerequisites));
  auto order = solution.findOrder(n, prerequisites);
  EXPECT_TRUE(verifyOrder(order, prerequisites));

  for (int i = 1; i < n; ++i) {
    prerequisites.emplace_back(i, i>>1);
  }
  EXPECT_TRUE(solution.canFinish(n, prerequisites));
  order = solution.findOrder(n, prerequisites);
  EXPECT_TRUE(verifyOrder(order, prerequisites));

  prerequisites.emplace_back(0, n-1);
  EXPECT_FALSE(solution.canFinish(n, prerequisites));
  EXPECT_EQ((vector<int>{}), solution.findOrder(n, prerequisites));

  prerequisites.pop_back();
  for (int i = 1; i < n; ++i) {
    prerequisites.emplace_back((i>>1)+n, i+n);
  }
  EXPECT_TRUE(solution.canFinish(n+n, prerequisites));
  order = solution.findOrder(n+n, prerequisites);
  EXPECT_TRUE(verifyOrder(order, prerequisites));

  prerequisites.emplace_back(n+n-1, n);
  EXPECT_FALSE(solution.canFinish(n+n, prerequisites));
  EXPECT_EQ((vector<int>{}), solution.findOrder(n+n, prerequisites));
}

}
