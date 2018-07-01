#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

  TEST(ReverseString, hello) {
    Solution solution;
    EXPECT_EQ("olleh", solution.reverseString("hello"));
  }

  TEST(ReverseString, empty) {
    Solution solution;
    EXPECT_EQ("", solution.reverseString(""));
  }

  TEST(ReverseString, onechar) {
    Solution solution;
    EXPECT_EQ("1", solution.reverseString("1"));
  }

  TEST(ReverseString, lenghteven) {
    Solution solution;
    EXPECT_EQ("4nel", solution.reverseString("len4"));
  }

  TEST(ReverseString, lengthodd) {
    Solution solution;
    EXPECT_EQ("7htgnel", solution.reverseString("length7"));
  }
} // anonymous namespace
