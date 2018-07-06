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

}
