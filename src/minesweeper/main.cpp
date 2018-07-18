#include <iostream>
#include <string>
#include <cstring>

#include "solution.cpp"

int main() {
  Solution solution;

  int h, w;
  int n = 0;
  std::string line;
  while (1) {
    std::cin >> h >> w;
    if (!h) {
      break;
    }

    if (n) {
      std::cout << '\n';
    }

    std::vector<string> input;
    for (int i = 0; i < h; ++i) {
      std::cin >> line;
      input.push_back(line);
    }

    solution.resolveField(input);

    std::cout << "Field #" << ++n << ":\n";
    for (int i = 0; i < h; ++i) {
      std::cout << input[i] << '\n';
    }
  }
  return 0;
}
