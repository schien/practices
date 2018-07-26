#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void output_vector(vector<int>&& vec) {
  for (int n : vec) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
}

int main() {
  vector<int> input = next_vector<int>();
  Solution solution(input);

  char op;
  while (1) {
    std::cin >> op;
    if (std::cin.eof()) {
      break;
    }

    switch(op) {
      case 's':
        output_vector(solution.shuffle());
        break;
      case 'r':
        output_vector(solution.reset());
        break;
      default:
        break;
    }
  }
  return 0;
}
