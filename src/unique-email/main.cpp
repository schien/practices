#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  vector<string> input = next_vector<string>();

  Solution solution;
  std::cout << solution.numUniqueEmails(input) << std::endl;

  return 0;
}
