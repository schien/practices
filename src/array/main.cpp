#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage] i {n x_1 ... x_n} {m y_1 ... y_m}\n"
            << "        t {n x_1 ... x_n} k\n"
            << "        m {n x_1 ... x_n}\n"
            << "        p {n x_1 ... x_n}\n"
            << "        d {n x_1 ... x_n}\n"
            << "        s {n x_1 ... x_n}\n"
            << "        k {n x_1 ... x_n} k\n"
            << "        3 {n x_1 ... x_n}\n"
            << "        l {n x_1 ... x_n}\n"
            << "        c {n [0|1|2]*}\n"
            << "        e {n x_1 ... x_n}\n"
            << "        j {n x_1 ... x_n}\n"
            << "        g {n x_1 ... x_n}\n"
            << "        x {n x_1 ... x_n}\n"
            << "        r {n x_1 ... x_n} t\n"
            << std::flush;
}

void output_vector(vector<int>& vec) {
  for (auto n : vec) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runIntersect() {
  std::vector<int> num1 = next_vector<int>();
  std::vector<int> num2 = next_vector<int>();

  Solution solution;
  auto output = solution.intersection(num1, num2);
  output_vector(output);

  output = solution.intersect(num1, num2);
  output_vector(output);
}

void runTopKFrequent() {
  std::vector<int> num = next_vector<int>();
  int k = next<int>();

  Solution solution;
  auto output = solution.topKFrequent(num, k);
  output_vector(output);
}

void runProductExceptSelf() {
  std::vector<int> num = next_vector<int>();

  Solution solution;
  auto output = solution.productExceptSelf(num);
  output_vector(output);
}

void runPermutation() {
  std::vector<int> num = next_vector<int>();

  Solution solution;
  auto output = solution.permute(num);
  for (auto vec : output) {
    output_vector(vec);
  }
}

void runFindDuplicate() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << solution.findDuplicate(num) << std::endl;
}

void runSubset() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.subsets(num);
  for (auto vec : output) {
    output_vector(vec);
  }
}

void runKthLargest() {
  std::vector<int> num = next_vector<int>();
  int k = next<int>();
  Solution solution;
  auto output = solution.findKthLargest(num, k);
  std::cout << output << std::endl;
}

void runIncreasingTriplet() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.increasingTriplet(num);
  std::cout << std::boolalpha << output << std::endl;
}

void runLIS() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.lengthOfLIS(num);
  std::cout << output << std::endl;
}

void runSortColors() {
  std::vector<int> input = next_vector<int>();
  Solution solution;
  solution.sortColors(input);
  output_vector(input);
}

void runFindPeakElement() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.findPeakElement(num);
  std::cout << output << std::endl;
}

void runJumpGame() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.canJump(num);
  std::cout << output << std::endl;
}

void runLargestNumber() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.largestNumber(num);
  std::cout << output << std::endl;
}

void runMaxProduct() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.maxProduct(num);
  std::cout << output << std::endl;
}

void runSearchRotate() {
  std::vector<int> num = next_vector<int>();
  int target = next<int>();
  Solution solution;
  auto output = solution.search(num, target);
  std::cout << output << std::endl;
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
    case 'd':
      runFindDuplicate();
      break;
    case 's':
      runSubset();
      break;
    case 'k':
      runKthLargest();
      break;
    case '3':
      runIncreasingTriplet();
      break;
    case 'l':
      runLIS();
      break;
    case 'c':
      runSortColors();
      break;
    case 'e':
      runFindPeakElement();
      break;
    case 'j':
      runJumpGame();
      break;
    case 'g':
      runLargestNumber();
      break;
    case 'x':
      runMaxProduct();
      break;
    case 'r':
      runSearchRotate();
      break;
    default:
      usage();
      break;
  }

  return 0;
}
