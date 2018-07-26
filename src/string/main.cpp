#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: a str1 str2\n"
            << "       s str1 str2\n"
            << "       g n str_1 ... str_n\n"
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
  std::vector<string> strs = next<vector<string>>();
  Solution solution;
  auto output = solution.groupAnagrams(strs);
  for (auto& vec: output) {
    for (auto& s:vec) {
      std::cout << s << ' ';
    }
    std::cout << '\n';
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
    default:
      usage();
      break;
  }

  return 0;
}
