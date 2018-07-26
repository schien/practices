#include "gtest/gtest.h"
#include <numeric>

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

TEST(GroupAnagram, empty) {
  Solution solution;
  vector<string> input{};
  EXPECT_EQ(vector<vector<string>>{}, solution.groupAnagrams(input));
}

TEST(GroupAnagram, example) {
  Solution solution;
  vector<string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
  auto output = solution.groupAnagrams(input);

  unordered_map<string, int> table;
  for (auto& vec:output) {
    for (int i = 0; i < vec.size(); ++i) {
      EXPECT_TRUE(solution.isAnagram(vec[0], vec[i]));
      ++table[vec[i]];
    }
  }

  for (auto& s:input) {
    --table[s];
  }

  for (auto& e:table) {
    EXPECT_EQ(0, e.second);
  }

  for (int i = 0; i < output.size(); ++i) {
    for (int j = i+1; j < output.size(); ++j) {
      EXPECT_FALSE(solution.isAnagram(output[i][0], output[j][0]));
    }
  }
}

TEST(GroupAnagram, large) {
  Solution solution;
  array<char, 512> buf;
  buf.fill('a');

  vector<string> input;
  for (int i = 1; i <= 512; ++i) {
    input.emplace_back(buf.data(), i);
  }

  auto output = solution.groupAnagrams(input);

  EXPECT_EQ(input.size(), output.size());

  for (auto& vec:output) {
    EXPECT_EQ(1, vec.size());
    EXPECT_EQ(input[vec[0].size()-1], vec[0]);
  }
}

}
