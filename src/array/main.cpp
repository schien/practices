#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage] i {n x_1 ... x_n} {m y_1 ... y_m}\n"
            << "        t {n x_1 ... x_n} k\n"
            << "        m {n x_1 ... x_n}\n"
            << "        p {n x_1 ... x_n}\n"
            << std::flush;
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

void runProductExceptSelf() {
  std::vector<int> num = next();

  Solution solution;
  auto output = solution.productExceptSelf(num);
  output_vector(output);
}

void runPermutation() {
  std::vector<int> num = next();

  Solution solution;
  auto output = solution.permute(num);
  for (auto vec : output) {
    output_vector(vec);
  }
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
    case 'm':
      runProductExceptSelf();
      break;
    case 'p':
      runPermutation();
      break;
    default:
      usage();
      break;
  }

  return 0;
}
