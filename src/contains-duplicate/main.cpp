#include <iostream>
#include <vector>

#include "solution.cpp"

int main() {
  uint32_t n;
  std::cin >> n;

  std::vector<int> input;
  input.reserve(n);
  while (n--) {
    int v;
    std::cin >> v;
    input.push_back(v);
  }

  Solution solution;
  auto output = solution.containsDuplicate(input);

  std::cout << output << std::endl;

  int k;
  std::cin >> k;
  output = solution.containsNearbyDuplicate(input, k);
  std::cout << output << std::endl;
  return 0;
}
