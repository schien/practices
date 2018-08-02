#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(CoinChangeTest, example) {
  Solution solution;

  vector<int> coins {
    1, 2, 5
  };

  EXPECT_EQ(3, solution.coinChange(coins, 11));

  coins = { 3 };
  EXPECT_EQ(-1, solution.coinChange(coins, 2));
}

TEST(CoinChangeTest, invalid) {
  Solution solution;

  vector<int> coins {};

  EXPECT_EQ(-1, solution.coinChange(coins, 11));
  EXPECT_EQ(0, solution.coinChange(coins, 0));

  coins = { 1 };
  EXPECT_EQ(0, solution.coinChange(coins, 0));
}

TEST(CoinChangeTest, basic) {
  Solution solution;

  vector<int> coins {1, 10, 100};

  for (int i = 1; i < 1000; ++i) {
    int expected = i%10 + ((i/10)%10) + (i/100);
    EXPECT_EQ(expected, solution.coinChange(coins, i));
  }
}

}
