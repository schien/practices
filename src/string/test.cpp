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

TEST(RomanToIntTest, basic) {
  Solution solution;

  vector<pair<string, int>> inputs {
    {"I", 1},
    {"IV", 4},
    {"V", 5},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000},
  };

  for (auto& e: inputs) {
    EXPECT_EQ(e.second, solution.romanToInt(e.first));
  }
}

TEST(RomanToIntTest, combined) {
  Solution solution;

  vector<pair<string, int>> inputs {
    {"II", 2}, {"III", 3}, {"VI", 6}, {"VII", 7}, {"VIII", 8},
    {"XX", 20}, {"XXX", 30}, {"LX", 60}, {"LXX", 70}, {"LXXX", 80},
    {"CC", 200}, {"CCC", 300}, {"DC", 600}, {"DCC", 700}, {"DCCC", 800},
    {"MM", 2000}, {"MMM", 3000},
    {"MMMDCCCLXXXVIII", 3888}, {"MMMCMXCIX", 3999},
  };

  for (auto& e: inputs) {
    EXPECT_EQ(e.second, solution.romanToInt(e.first));
  }
}

TEST(LetterCombinationsTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<string>{}, solution.letterCombinations(""));
}

TEST(LetterCombinationsTest, one_digit) {
  Solution solution;
  vector<pair<string, vector<string>>> tests {
    {"2", {"a", "b", "c"}},
    {"3", {"d", "e", "f"}},
    {"4", {"g", "h", "i"}},
    {"5", {"j", "k", "l"}},
    {"6", {"m", "n", "o"}},
    {"7", {"p", "q", "r", "s"}},
    {"8", {"t", "u", "v"}},
    {"9", {"w", "x", "y", "z"}},
  };

  for (auto& t : tests) {
    EXPECT_EQ(t.second, solution.letterCombinations(t.first));
  }
}

TEST(LetterCombinationsTest, two_digit) {
  Solution solution;
  vector<pair<string, vector<string>>> tests {
    {"2", {"a", "b", "c"}},
    {"3", {"d", "e", "f"}},
    {"4", {"g", "h", "i"}},
    {"5", {"j", "k", "l"}},
    {"6", {"m", "n", "o"}},
    {"7", {"p", "q", "r", "s"}},
    {"8", {"t", "u", "v"}},
    {"9", {"w", "x", "y", "z"}},
  };

  for (auto& f : tests) {
    for (auto& s: tests) {
      vector<string> expected;
      for (auto c1: f.second) {
        for (auto c2: s.second) {
          expected.push_back(c1+c2);
        }
      }
      sort(expected.begin(), expected.end());

      auto output = solution.letterCombinations(f.first + s.first);
      sort(output.begin(), output.end());
      EXPECT_EQ(expected, output);
    }
  }
}

TEST(WordBreakTest, empty) {
  Solution solution;

  vector<string> wordDict{"a"};
  EXPECT_FALSE(solution.wordBreak("", wordDict));

  wordDict.clear();
  EXPECT_FALSE(solution.wordBreak("a", wordDict));
}

TEST(WordBreakTest, small) {
  Solution solution;

  vector<string> wordDict {
    "a", "b", "c"
  };

  for (int i = 1; i < (1<<3); ++i) {
    string s{""};
    for (int j = 0; j < 3; ++j) {
      if (i&(1<<j)) {
        s += wordDict[j];
      }
    }
    EXPECT_TRUE(solution.wordBreak(s, wordDict));
  }

  string input = "abcd";
  for (int i = 0; i < input.size(); ++i) {
    swap(input[i], input[3]);
    EXPECT_FALSE(solution.wordBreak(input, wordDict));
  }
}

TEST(WordBreakTest, large) {
  Solution solution;

  vector<string> wordDict;
  for (int i = 1; i < 20; ++i) {
    wordDict.emplace_back(i, 'a');
  }

  string input(1000, 'a');
  EXPECT_TRUE(solution.wordBreak(input, wordDict));

  input += 'b';
  for (int i = 0; i < input.length(); ++i) {
    swap(input[i], input[1000]);
    EXPECT_FALSE(solution.wordBreak(input, wordDict));
  }
}

TEST(DecodeWaysTest, empty) {
  Solution solution;
  EXPECT_EQ(0, solution.numDecodings(""));
}

TEST(DecodeWaysTest, invalid) {
  Solution solution;
  EXPECT_EQ(0, solution.numDecodings("0"));

  string input{"123456789"};
  for (int i = 0; i < input.size()-1; ++i) {
    char oc1 = input[i], oc2 = input[i+1];
    input[i] = '0';
    input[i+1] = '0';
    EXPECT_EQ(0, solution.numDecodings(input));
    input[i] = oc1;
    input[i+1] = oc2;
  }
}

TEST(DecodeWaysTest, example) {
  Solution solution;

  string input{"1"};
  EXPECT_EQ(1, solution.numDecodings(input));

  input = "12";
  EXPECT_EQ(2, solution.numDecodings(input));

  input = "11111";
  EXPECT_EQ(8, solution.numDecodings(input));

  input = "10101";
  EXPECT_EQ(1, solution.numDecodings(input));

  input = "27";
  EXPECT_EQ(1, solution.numDecodings(input));

  input = "1918171615141310";
  EXPECT_EQ(128, solution.numDecodings(input));

  input = "23242526";
  EXPECT_EQ(16, solution.numDecodings(input));
}

}
