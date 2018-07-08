#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  string s = next<string>(), t = next<string>();
  //std::cin >> s >> t;

  Solution solution;
  std::cout << "isAnagram: " << solution.isAnagram(s, t) << std::endl;
  std::cout << "strStr: " << solution.strStr(s, t) << std::endl;

  return 0;
}
