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

}
