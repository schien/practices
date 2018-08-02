#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: a str1 str2\n"
            << "       s str1 str2\n"
            << "       g n str_1 ... str_n\n"
            << "       r str1\n"
            << "       d str1\n"
            << std::flush;
}

void runAnagram() {
  string s = next<string>(), t = next<string>();

  Solution solution;
  std::cout << "isAnagram: " << solution.isAnagram(s, t) << std::endl;
}

void runStrStr() {
  string s = next<string>(), t = next<string>();

  Solution solution;
  std::cout << "strStr: " << solution.strStr(s, t) << std::endl;
}

void runGroupAnagram() {
  std::vector<string> strs = next_vector<string>();
  Solution solution;
  auto output = solution.groupAnagrams(strs);
  for (auto& vec: output) {
    for (auto& s:vec) {
      std::cout << s << ' ';
    }
    std::cout << '\n';
  }
}

void runRomanToInt() {
  string s = next<string>();

  Solution solution;
  std::cout << solution.romanToInt(s) << std::endl;
}

void runLetterCombinations() {
  string s = next<string>();

  Solution solution;
  auto output = solution.letterCombinations(s);

  for (auto s : output) {
    std::cout << s << std::endl;
  }
}

int main() {
  char op;
  std::cin >> op;

  switch(op) {
    case 'a':
      runAnagram();
      break;
    case 's':
      runStrStr();
      break;
    case 'g':
      runGroupAnagram();
      break;
    case 'r':
      runRomanToInt();
      break;
    case 'd':
      runLetterCombinations();
      break;
    default:
      usage();
      break;
  }

  return 0;
}
