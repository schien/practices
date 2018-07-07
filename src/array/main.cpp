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

int main() {
  std::vector<int> num1 = read_array_input();
  std::vector<int> num2 = read_array_input();

  Solution solution;
  auto output = solution.intersection(num1, num2);

  for (auto n : output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
  return 0;
}
