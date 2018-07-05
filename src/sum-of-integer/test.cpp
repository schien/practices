#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(SumOfIntegerTest, zero) {
  Solution solution;

  EXPECT_EQ(0, solution.getSum(0, 0));
}

TEST(SumOfIntegerTest, normal) {
  Solution solution;

  int a = 1, b = 2;
  EXPECT_EQ(a+b, solution.getSum(a, b));
}

TEST(SumOfIntegerTest, negative) {
  Solution solution;

  int a = 1, b = -2;
  EXPECT_EQ(a+b, solution.getSum(a, b));
}

TEST(SumOfIntegerTest, two_negative) {
  Solution solution;

  int a = -1, b = -2;
  EXPECT_EQ(a+b, solution.getSum(a, b));
}

TEST(SumOfIntegerTest, int_min_max) {
  Solution solution;

  int a = INT_MIN, b = INT_MAX;
  EXPECT_EQ(a+b, solution.getSum(a, b));
}

}
