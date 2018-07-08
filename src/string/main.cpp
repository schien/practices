#include <iostream>

#include "solution.cpp"

int main() {
  string s, t;
  std::cin >> s >> t;

  Solution solution;
  auto output = solution.isAnagram(s, t);

  std::cout << output << std::endl;

  return 0;
}
