#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(UniquePathTest, example) {
  Solution solution;
  EXPECT_EQ(3, solution.uniquePaths(3, 2));

  EXPECT_EQ(1, solution.uniquePaths(1000000, 1));
  EXPECT_EQ(1, solution.uniquePaths(1, 1000000));

  EXPECT_EQ(1000000, solution.uniquePaths(1000000, 2));
  EXPECT_EQ(1000000, solution.uniquePaths(2, 1000000));

  EXPECT_EQ(500500, solution.uniquePaths(1000, 3));
  EXPECT_EQ(500500, solution.uniquePaths(3, 1000));
}

}
