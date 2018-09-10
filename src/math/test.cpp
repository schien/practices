#include "gtest/gtest.h"

#include "solution.cpp"

#include <cmath>

namespace {

TEST(MathTest, example) {
  Solution solution;

  for (int i = 0; i < 1000000; ++i) {
    EXPECT_EQ(1.0, solution.myPow(1.0, i));
  }

  EXPECT_EQ(1.0, solution.myPow(1.0, INT_MAX));
  EXPECT_EQ(1.0, solution.myPow(1.0, INT_MIN));

  for (int i = 0; i < 50; ++i) {
    EXPECT_EQ(std::pow(2.0, i), solution.myPow(2.0, i));
  }
}

}
