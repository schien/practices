#include <iostream>

#include "solution.cpp"

std::vector<int> read_array_input() {
  std::vector<int> result;
  int n;
  std::cin >> n;
  result.reserve(n);
  for (int i = 0; i < n; ++i) {
    int v;
    std::cin >> v;
    result.push_back(v);
  }
  return result;
}

void output_vector(vector<int>& vec) {
  for (auto n : vec) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> num1 = read_array_input();
  std::vector<int> num2 = read_array_input();

  Solution solution;
  auto output = solution.intersection(num1, num2);
  output_vector(output);

  output = solution.intersect(num1, num2);
  output_vector(output);

  return 0;
}
