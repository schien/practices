#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(JollyJumpersTest, example) {
  Solution solution;
  vector<int> input = {1, 4, 2, 3};
  EXPECT_TRUE(solution.isJolly(input));
  input = {1, 4, 2, -1, 6};
  EXPECT_FALSE(solution.isJolly(input));
}

TEST(JollyJumpersTest, one) {
  Solution solution;
  vector<int> input = {0};
  EXPECT_TRUE(solution.isJolly(input));
}

TEST(JollyJumpersTest, int_limit) {
  Solution solution;
  vector<int> input = {INT_MAX, INT_MAX-1};
  EXPECT_TRUE(solution.isJolly(input));
  input = {INT_MIN, INT_MIN+1};
  EXPECT_TRUE(solution.isJolly(input));

  input = {INT_MAX, INT_MIN};
  EXPECT_FALSE(solution.isJolly(input));
}

}
