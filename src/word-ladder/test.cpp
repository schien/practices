#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(WordLadderTest, invalid) {
  Solution solution;
  vector<string> wordList{"a"};
  EXPECT_EQ(0, solution.ladderLength("a", "b", wordList));
}

TEST(WordLadderTest, one_char) {
  Solution solution;
  vector<string> wordList;
  for (char c = 'a'; c <= 'z'; ++c) {
    wordList.emplace_back(1, c);
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    for (char tc = 'a'; tc <= 'z'; ++tc) {
      if (c == tc) continue;
      EXPECT_EQ(2, solution.ladderLength(string(1, c), string(1,tc), wordList));
    }
  }
}

TEST(WordLadderTest, two_char) {
  Solution solution;
  vector<string> wordList;

  string tmp{"  "};
  for (char c = 'a'; c <= 'z'; ++c) {
    for (char c2 = 'a'; c2 <= 'z'; ++c2) {
      tmp[0] = c;
      tmp[1] = c2;
    }
    wordList.push_back(tmp);
  }
  for (int i = 0; i < wordList.size(); ++i) {
    for (int j = 0; j < wordList.size(); ++j) {
      if (i == j) continue;
      EXPECT_EQ(2, solution.ladderLength(wordList[i], wordList[j], wordList));
    }
  }
}

TEST(WordLadderTest, unreachable) {
  Solution solution;
  vector<string> wordList {
    "aa", "ab", "ba", "bb", "cc"
  };

  for (int i = 0; i < wordList.size()-1; ++i) {
    EXPECT_EQ(0, solution.ladderLength(wordList[i], wordList.back(), wordList));
  }
}

}
