#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(FirstUniqueInStringTest, empty_string) {
  string empty;
  Solution solution;
  EXPECT_EQ(-1, solution.firstUniqChar(empty));
}

TEST(FirstUniqueInStringTest, one_char) {
  string input("a");
  Solution solution;
  EXPECT_EQ(0, solution.firstUniqChar(input));
}

TEST(FirstUniqueInStringTest, middle) {
  string input("aba");
  Solution solution;
  EXPECT_EQ(1, solution.firstUniqChar(input));
}

TEST(FirstUniqueInStringTest, last) {
  string input("aab");
  Solution solution;
  EXPECT_EQ(input.size()-1, solution.firstUniqChar(input));
}

TEST(FirstUniqueInStringTest, multiple_unique) {
  string input("abcdefghijklmnopqrstuvwxyz");
  Solution solution;
  EXPECT_EQ(0, solution.firstUniqChar(input));
}

TEST(FirstUniqueInStringTest, no_unique) {
  string input("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
  Solution solution;
  EXPECT_EQ(-1, solution.firstUniqChar(input));
}

TEST(FirstUniqueInStringTest, long_string) {
  string input(1000000, 'a');
  input[1000000-1] = 'b';

  Solution solution;
  EXPECT_EQ(1000000-1, solution.firstUniqChar(input));
}

TEST(FirstUniqueInStringTest, no_unique_long_string) {
  string input(1000000, 'a');

  Solution solution;
  EXPECT_EQ(-1, solution.firstUniqChar(input));
}

}
