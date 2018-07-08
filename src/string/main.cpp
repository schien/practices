#include <iostream>

#include "solution.cpp"

int main() {
  string s, t;
  std::cin >> s >> t;

  Solution solution;
  std::cout << "isAnagram: " << solution.isAnagram(s, t) << std::endl;
  std::cout << "strStr: " << solution.strStr(s, t) << std::endl;

  return 0;
}
