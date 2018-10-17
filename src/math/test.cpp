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

TEST(SelfDividingNumbersTest, invalid) {
  Solution solution;

  EXPECT_EQ(vector<int>{}, solution.selfDividingNumbers(-1, 2));
  EXPECT_EQ(vector<int>{}, solution.selfDividingNumbers(-1, 0));
  EXPECT_EQ(vector<int>{}, solution.selfDividingNumbers(-2, -1));
  EXPECT_EQ(vector<int>{}, solution.selfDividingNumbers(0, 1));
  EXPECT_EQ(vector<int>{}, solution.selfDividingNumbers(2, 1));
}

TEST(SelfDividingNumbersTest, example) {
  Solution solution;

  vector<int> expect{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
  EXPECT_EQ(expect, solution.selfDividingNumbers(1,22));

  while (expect.size() > 1) {
    int right = expect.back() -1;
    expect.pop_back();
    EXPECT_EQ(expect, solution.selfDividingNumbers(1,right));
  }
}

TEST(NthDigitTest, invalid) {
  Solution solution;

  EXPECT_EQ(-1, solution.findNthDigit(0));
  EXPECT_EQ(-1, solution.findNthDigit(-1));
  EXPECT_EQ(-1, solution.findNthDigit(INT_MIN));
}

TEST(NthDigitTest, example) {
  Solution solution;

  string target;
  for (int i = 1; i < 1000000; ++i) {
    target += to_string(i);
  }

  for (int i = 0; i < target.size(); ++i) {
    EXPECT_EQ(target[i]-'0', solution.findNthDigit(i+1));
  }
}

TEST(CountBitsTest, example) {
  Solution solution;

  auto populate = [](unsigned int x) {
    x -= ((x >> 1) & 0x55555555);
    x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
    x = (((x >> 4) + x) & 0x0f0f0f0f);
    x += (x >> 8);
    x += (x >> 16);
    return(x & 0x0000003f);
  };

  auto output = solution.countBits(100000);
  for (int i = 0; i <= 100000; ++i) {
    EXPECT_EQ(populate(i), output[i]);
  }
}

}
