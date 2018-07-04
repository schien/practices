#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(PowerOfThreeTest, zero) {
  Solution solution;
  EXPECT_FALSE(solution.isPowerOfThree(0));
}

TEST(PowerOfThreeTest, one) {
  Solution solution;
  EXPECT_TRUE(solution.isPowerOfThree(1));
}

TEST(PowerOfThreeTest, all_pow_of_3) {
  Solution solution;

  int n = 3;
  for (int i = 0; i < 19; ++i) {
    EXPECT_TRUE(solution.isPowerOfThree(n));
    n *= 3;
  }
}

TEST(PowerOfThreeTest, int_max) {
  Solution solution;
  EXPECT_FALSE(solution.isPowerOfThree(INT_MAX));
}

TEST(PowerOfThreeTest, all_non_power_of_3_less_than_1m) {
  Solution solution;

  int next_po3 = 1;
  for (int i = 0; i < 100000000; ++i) {
    if (i == next_po3) {
      next_po3 *= 3;
      continue;
    }

    EXPECT_FALSE(solution.isPowerOfThree(i));
  }
}

}
