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

TEST(PalindromePartitionTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<vector<string>>{{}}, solution.partition(""));
}

TEST(PalindromePartitionTest, example) {
  Solution solution;
  EXPECT_EQ(vector<vector<string>>{{"a"}}, solution.partition("a"));

  EXPECT_EQ((vector<vector<string>>{{"aa"}, {"a","a"}}), solution.partition("aa"));

  EXPECT_EQ((vector<vector<string>>{{"a","b"}}), solution.partition("ab"));

  EXPECT_EQ((vector<vector<string>>{{"aba"}, {"a","b","a"}}), solution.partition("aba"));

  EXPECT_EQ((vector<vector<string>>{
               {"ababa"},
               {"a", "b", "aba"},
               {"a", "bab", "a"},
               {"aba", "b", "a"},
               {"a", "b", "a", "b", "a"},
             }), solution.partition("ababa"));
}

TEST(EvalRPNTest, invalid) {
  Solution solution;
  vector<string> input;
  EXPECT_THROW(solution.evalRPN(input), runtime_error);
  input = {"a"};
  EXPECT_THROW(solution.evalRPN(input), invalid_argument);
  input = {"1", "2"};
  EXPECT_THROW(solution.evalRPN(input), runtime_error);
  input = {"/", "1", "2", "3"};
  EXPECT_THROW(solution.evalRPN(input), runtime_error);
  input = {"1", "*", "2", "3"};
  EXPECT_THROW(solution.evalRPN(input), runtime_error);
  input = {"1", "2", "+", "3"};
  EXPECT_THROW(solution.evalRPN(input), runtime_error);
  input = {"1", "2", "3", "-"};
  EXPECT_THROW(solution.evalRPN(input), runtime_error);
}

TEST(EvalRPNTest, one) {
  Solution solution;
  vector<string> input{"0"};
  EXPECT_EQ(0, solution.evalRPN(input));

  for (auto n : {-10, -1, 1, 10}) {
    input[0] = to_string(n);
    EXPECT_EQ(n, solution.evalRPN(input));
  }
}

TEST(EvalRPNTest, example) {
  Solution solution;
  vector<string> input{"2", "1", "+", "3", "*"};
  EXPECT_EQ(9, solution.evalRPN(input));

  input = {"4", "13", "5", "/", "+"};
  EXPECT_EQ(6, solution.evalRPN(input));

  input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  EXPECT_EQ(22, solution.evalRPN(input));
}

TEST(CalculatorTest, empty) {
  Solution solution;
  string input;
  EXPECT_EQ(0, solution.calculate(input));
}

TEST(CalculatorTest, only_digit) {
  Solution solution;
  string input{"1234567890"};
  EXPECT_EQ(1234567890, solution.calculate(input));
}

TEST(CalculatorTest, only_add_minus) {
  Solution solution;
  string input{"1+2-3+4-5+6-7+8-9+10"};
  EXPECT_EQ(7, solution.calculate(input));
}

TEST(CalculatorTest, only_mul_div) {
  Solution solution;
  string input{"1*2/2*3/3*4/4*5/5*6/6*7/7*8/7*9/9*10/10"};
  EXPECT_EQ(1, solution.calculate(input));
  input = "1/2*3/4*5/6*7/8*9/10";
  EXPECT_EQ(0, solution.calculate(input));
}

TEST(CalculatorTest, mixed) {
  Solution solution;
  string input{"1+2*3-4/5+6*7/8-9+10"};
  EXPECT_EQ(13, solution.calculate(input));
}

TEST(ToLowerCaseTest, empty) {
  Solution solution;
  EXPECT_EQ("", solution.toLowerCase(""));
}

TEST(ToLowerCaseTest, single_char) {
  Solution solution;

  for (char c = 'a'; c <= 'z'; ++c) {
    EXPECT_EQ(string(1,c), solution.toLowerCase(string(1, c)));
    EXPECT_EQ(string(1,c), solution.toLowerCase(string(1, toupper(c))));
  }
}

TEST(ToLowerCaseTest, multi_char) {
  Solution solution;

  for (int i = 2; i < 100; ++i) {
    string input(i, 'A');
    string expected(i, 'a');
    EXPECT_EQ(expected, solution.toLowerCase(input));
  }
}

TEST(JewelsAndStonesTest, empty) {
  Solution solution;

  EXPECT_EQ(0, solution.numJewelsInStones("", ""));
  EXPECT_EQ(0, solution.numJewelsInStones("abcde", ""));
  EXPECT_EQ(0, solution.numJewelsInStones("", "abcde"));
}

TEST(JewelsAndStonesTest, simple) {
  Solution solution;
  string stones{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  for (int i = 0; i < 26; ++i) {
    EXPECT_EQ(1, solution.numJewelsInStones(string(1, 'a'+i), stones));
    EXPECT_EQ(1, solution.numJewelsInStones(string(1, 'A'+i), stones));
    EXPECT_EQ(2, solution.numJewelsInStones(string{(char)('a'+i), (char)('A'+i)}, stones));
  }
}

TEST(UniqueMorseCodesTest, empty) {
  Solution solution;
  vector<string> input;
  EXPECT_EQ(0, solution.uniqueMorseRepresentations(input));

  input = {"", "", "", ""};
  EXPECT_EQ(1, solution.uniqueMorseRepresentations(input));
}

TEST(UniqueMorseCodesTest, one_char) {
  Solution solution;
  vector<string> input;
  for (char c = 'a'; c <= 'z'; ++c) {
    input.emplace_back(1, c);
  }
  EXPECT_EQ(input.size(), solution.uniqueMorseRepresentations(input));
}

TEST(UniqueMorseCodesTest, example) {
  Solution solution;
  vector<string> input = {
    "gin", "zen", "gig", "msg"
  };
  EXPECT_EQ(2, solution.uniqueMorseRepresentations(input));
}

TEST(LetterCasePermutationTest, empty) {
  Solution solution;
  EXPECT_EQ(vector<string>{""}, solution.letterCasePermutation(""));
}

TEST(LetterCasePermutationTest, one_char) {
  Solution solution;

  for (char c = '0'; c <= '9'; ++c) {
    EXPECT_EQ((vector<string>{string(1,c)}), solution.letterCasePermutation(string(1, c)));
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    EXPECT_EQ((vector<string>{string(1,c), string(1, toupper(c))}), solution.letterCasePermutation(string(1, c)));
  }

  for (char c = 'A'; c <= 'Z'; ++c) {
    EXPECT_EQ((vector<string>{string(1,tolower(c)), string(1, c)}), solution.letterCasePermutation(string(1, c)));
  }
}

TEST(LetterCasePermutationTest, multi_char) {
  Solution solution;

  string input{"0?"};

  for (char c = 'a'; c <= 'z'; ++c) {
    input[1] = c;
    vector<string> expected(2, "0?");
    expected[0][1] = c;
    expected[1][1] = toupper(c);
    EXPECT_EQ(expected, solution.letterCasePermutation(input));
  }

  input = "?0";
  for (char c = 'A'; c <= 'Z'; ++c) {
    input[0] = c;
    vector<string> expected(2, "?0");
    expected[0][0] = tolower(c);
    expected[1][0] = c;
    EXPECT_EQ(expected, solution.letterCasePermutation(input));
  }

  input = "1?9";
  for (char c = 'a'; c <= 'z'; ++c) {
    input[1] = c;
    vector<string> expected(2, "1?9");
    expected[0][1] = c;
    expected[1][1] = toupper(c);
    EXPECT_EQ(expected, solution.letterCasePermutation(input));
  }

  input = "?5?";
  for (char c1 = 'a'; c1 <= 'z'; ++c1) {
    input[0] = c1;
    for (char c2 = 'A'; c2 <= 'Z'; ++c2) {
      input[2] = c2;
      vector<string> expected(4, "?5?");
      expected[0][0] = tolower(c1);
      expected[1][0] = tolower(c1);
      expected[2][0] = toupper(c1);
      expected[3][0] = toupper(c1);
      expected[0][2] = tolower(c2);
      expected[1][2] = toupper(c2);
      expected[2][2] = tolower(c2);
      expected[3][2] = toupper(c2);
      EXPECT_EQ(expected, solution.letterCasePermutation(input));
    }
  }
}

TEST(ReturnToOriginTest, empty) {
  Solution solution;
  EXPECT_TRUE(solution.judgeCircle(""));
}

TEST(ReturnToOriginTest, small) {
  Solution solution;

  EXPECT_FALSE(solution.judgeCircle("U"));
  EXPECT_FALSE(solution.judgeCircle("D"));
  EXPECT_FALSE(solution.judgeCircle("L"));
  EXPECT_FALSE(solution.judgeCircle("R"));

  EXPECT_TRUE(solution.judgeCircle("UD"));
  EXPECT_TRUE(solution.judgeCircle("DU"));
  EXPECT_TRUE(solution.judgeCircle("LR"));
  EXPECT_TRUE(solution.judgeCircle("RL"));
}

}
