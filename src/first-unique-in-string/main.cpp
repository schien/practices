#include <iostream>
#include <vector>

#include "solution.cpp"

int main() {
  std::string input;
  std::cin >> input;

  Solution solution;
  auto output = solution.firstUniqChar(input);

  std::cout << output << std::endl;

  return 0;
}
