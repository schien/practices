#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(HappyNumberTest, zero) {
  Solution solution;
  EXPECT_FALSE(solution.isHappy(0));
}

TEST(HappyNumberTest, one) {
  Solution solution;
  EXPECT_TRUE(solution.isHappy(1));
}

TEST(HappyNumberTest, two) {
  Solution solution;
  EXPECT_FALSE(solution.isHappy(2));
}

TEST(HappyNumberTest, negative) {
  Solution solution;
  EXPECT_FALSE(solution.isHappy(-1));
}

TEST(AddDigitsTest, num_lt_10) {
  Solution solution;
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(i, solution.addDigits(i));
  }
}

TEST(AddDigitsTest, 1m) {
  Solution solution;
  EXPECT_EQ(1, solution.addDigits(1000000));
}

TEST(UglyNumberTest, zero) {
  Solution solution;
  EXPECT_FALSE(solution.isUgly(0));
}

TEST(UglyNumberTest, one) {
  Solution solution;
  EXPECT_TRUE(solution.isUgly(1));
}

TEST(UglyNumberTest, ugly_lt_10) {
  Solution solution;
  for (auto n : vector<int>{2, 3, 4, 5, 6, 8, 9}) {
    EXPECT_TRUE(solution.isUgly(n));
  }
}

TEST(UglyNumberTest, seven) {
  Solution solution;
  EXPECT_FALSE(solution.isUgly(7));
}

TEST(UglyNumberTest, negative) {
  Solution solution;
  EXPECT_FALSE(solution.isUgly(-1));
}

}
