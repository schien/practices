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
  for (int i = 0; i < 1000000; ++i) {
    if (i == next_po3) {
      next_po3 *= 3;
      continue;
    }

    EXPECT_FALSE(solution.isPowerOfThree(i));
  }
}

TEST(PowerOfThreeTest, int_min) {
  Solution solution;
  EXPECT_FALSE(solution.isPowerOfThree(INT_MIN));
}

TEST(PowerOfTwoTest, zero) {
  Solution solution;
  EXPECT_FALSE(solution.isPowerOfTwo(0));
}

TEST(PowerOfTwoTest, one) {
  Solution solution;
  EXPECT_TRUE(solution.isPowerOfTwo(1));
}

TEST(PowerOfTwoTest, all_pow_of_2) {
  Solution solution;

  for (int i = 0; i < 31; ++i) {
    EXPECT_TRUE(solution.isPowerOfTwo(1 << i));
  }
}

TEST(PowerOfTwoTest, all_non_power_of_2_less_than_1m) {
  Solution solution;

  int next_po2 = 1;
  for (int i = 0; i < 1000000; ++i) {
    if (i == next_po2) {
      next_po2 <<= 1;
      continue;
    }

    EXPECT_FALSE(solution.isPowerOfTwo(i));
  }
}

TEST(PowerOfTwoTest, negative) {
  Solution solution;

  EXPECT_FALSE(solution.isPowerOfTwo(INT_MIN));
}


}
