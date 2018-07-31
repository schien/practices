#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  Solution solution;

  while (1) {
    std::vector<std::string> black;
    for (int i = 0; i < 5; ++i) {
      string card = next<string>();
      if (std::cin.eof()) {
        return 0;
      }
      black.push_back(card);
    }
    std::vector<std::string> white;
    for (int i = 0; i < 5; ++i) {
      string card = next<string>();
      if (std::cin.eof()) {
        return 0;
      }
      white.push_back(card);
    }

    auto result = solution.compare(black, white);
    if (result > 0) {
      cout << "Black wins.\n";
    } else if (result < 0) {
      cout << "White wins.\n";
    } else {
      cout << "Tie.\n";
    }
  };

  return 0;
}
