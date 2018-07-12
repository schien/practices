#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage] i {n x_1 ... x_n} {m y_1 ... y_m}" << std::endl
            << "        t {n x_1 ... x_n} k" << std::endl;
}

void output_vector(vector<int>& vec) {
  for (auto n : vec) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runIntersect() {
  std::vector<int> num1 = next();
  std::vector<int> num2 = next();

  Solution solution;
  auto output = solution.intersection(num1, num2);
  output_vector(output);

  output = solution.intersect(num1, num2);
  output_vector(output);
}

void runTopKFrequent() {
  std::vector<int> num = next();
  int k = next<int>();

  Solution solution;
  auto output = solution.topKFrequent(num, k);
  output_vector(output);
}

int main() {
  char op = next<char>();

  switch(op) {
    case 'i':
      runIntersect();
      break;
    case 't':
      runTopKFrequent();
      break;
    default:
      usage();
      break;
  }

  return 0;
}
