#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

  TEST(ReverseVowel, hello) {
    Solution solution;
    EXPECT_EQ("holle", solution.reverseVowels("hello"));
  }

  TEST(ReverseVowel, empty) {
    Solution solution;
    EXPECT_EQ("", solution.reverseVowels(""));
  }

  TEST(ReverseVowel, onechar) {
    Solution solution;
    EXPECT_EQ("a", solution.reverseVowels("a"));
  }

  TEST(ReverseVowel, onevowel) {
    Solution solution;
    EXPECT_EQ("ab", solution.reverseVowels("ab"));
  }

  TEST(ReverseVowel, twovowel) {
    Solution solution;
    EXPECT_EQ("ebcdaf", solution.reverseVowels("abcdef"));
  }

  TEST(ReverseVowel, fivevowel) {
    Solution solution;
    EXPECT_EQ("uoiea", solution.reverseVowels("aeiou"));
  }

  TEST(ReverseVowel, uppercase) {
    Solution solution;
    EXPECT_EQ("UOIEAuoiea", solution.reverseVowels("aeiouAEIOU"));
  }
} // anonymous namespace
