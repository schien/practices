#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(AnagramTest, different_size) {
  string s{"a"};
  string t{"aa"};
  Solution solution;

  EXPECT_FALSE(solution.isAnagram(s, t));
}

TEST(AnagramTest, same) {
  string s{"abcdefghijklmnopqrstuvwxyz"};
  Solution solution;

  EXPECT_TRUE(solution.isAnagram(s, s));
}

TEST(AnagramTest, different) {
  string s{"cat"};
  string t{"rat"};
  Solution solution;

  EXPECT_FALSE(solution.isAnagram(s, t));
}

TEST(AnagramTest, anagram) {
  string s{"anagram"};
  string t{"nagaram"};
  Solution solution;

  EXPECT_TRUE(solution.isAnagram(s, s));
}

TEST(AnagramTest, long_string) {
  string s(1000000, 'a');
  string t(1000000, 'b');
  Solution solution;

  EXPECT_FALSE(solution.isAnagram(s, t));
  EXPECT_TRUE(solution.isAnagram(s, s));
}

TEST(StrStrTest, simple) {
  string haystack{"hello"};
  string needle{"ll"};
  Solution solution;

  EXPECT_EQ(2, solution.strStr(haystack, needle));
}

TEST(StrStrTest, not_found) {
  string haystack{"hello"};
  string needle{"llz"};
  Solution solution;

  EXPECT_EQ(-1, solution.strStr(haystack, needle));
}

TEST(StrStrTest, long_string) {
  string haystack(2000000, 'a');
  string needle(1000000, 'b');
  Solution solution;

  EXPECT_EQ(-1, solution.strStr(haystack, needle));
  EXPECT_EQ(0, solution.strStr(haystack, haystack));
}

TEST(StrStrTest, long_needle) {
  string haystack{"hello"};
  string needle{"helloworld"};
  Solution solution;

  EXPECT_EQ(-1, solution.strStr(haystack, needle));
}

TEST(StrStrTest, empty_needle) {
  string haystack{"hello"};
  string needle{""};
  Solution solution;

  EXPECT_EQ(0, solution.strStr(haystack, needle));
}

TEST(StrStrTest, empty_haystack) {
  string haystack{""};
  string needle{"world"};
  Solution solution;

  EXPECT_EQ(-1, solution.strStr(haystack, needle));
}

}
