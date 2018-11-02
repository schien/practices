#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int target = 0;

int guess(int num) {
  if (num == target) { return 0; }
  else if (num > target) { return -1; }
  else { return 1; }
}

int main() {
  int n = next<int>();
  target = next<int>();
  Solution solution;
  std::cout << solution.guessNumber(n) << std::endl;
  return 0;
}
