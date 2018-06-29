#include <iostream>
#include <string>

#include "solution.cpp"

int main() {
  Solution solution;

  std::string line;
  while (std::cin >> line) {
    std::cout << solution.reverseString(line) << '\n';
    if (std::cin.eof()) {
      break;
    }
  }
  std::cout.flush();

  return 0;
}
