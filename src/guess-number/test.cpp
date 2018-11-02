#include "gtest/gtest.h"

#include "solution.cpp"

int target = 0;

int guess(int num) {
  if (num == target) { return 0; }
  else if (num > target) { return -1; }
  else { return 1; }
}

namespace {

TEST(GuessNumberTest, example) {
  Solution solution;
  EXPECT_EQ(-1, solution.guessNumber(-1));
  EXPECT_EQ(-1, solution.guessNumber(0));

  target = 1;
  EXPECT_EQ(target, solution.guessNumber(1));
  EXPECT_EQ(target, solution.guessNumber(1000));
  EXPECT_EQ(target, solution.guessNumber(99));
  EXPECT_EQ(target, solution.guessNumber(INT_MAX));

  target = INT_MAX;
  EXPECT_EQ(target, solution.guessNumber(INT_MAX));

  for (int n = 1; n < 1000; ++n) {
    for (target = 1; target <= n; ++target) {
      EXPECT_EQ(target, solution.guessNumber(n));
    }
  }
}

}
