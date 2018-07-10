#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(HouseRobberTest, empty) {
  Solution solution;

  vector<int> empty;
  EXPECT_EQ(0, solution.rob(empty));
}

TEST(HouseRobberTest, one) {
  Solution solution;

  vector<int> one{1};
  EXPECT_EQ(1, solution.rob(one));
}

TEST(HouseRobberTest, two) {
  Solution solution;

  vector<int> two{1, 0};
  EXPECT_EQ(1, solution.rob(two));

  two = vector<int>{0, 1};
  EXPECT_EQ(1, solution.rob(two));
}

TEST(HouseRobberTest, more) {
  Solution solution;

  vector<int> input{0, 1, 2, 2};
  EXPECT_EQ(3, solution.rob(input));

  input = vector<int>{0, 1, 3, 1, 0};
  EXPECT_EQ(3, solution.rob(input));
}

TEST(HouseRobberTest, large) {
  Solution solution;

  vector<int> input(1000000-1, 2);
  EXPECT_EQ(1000000, solution.rob(input));

  input = vector<int>(1000000, 2);
  input[0] = 0;
  input[1] = 1;
  EXPECT_EQ(1000000-1, solution.rob(input));
}

}
