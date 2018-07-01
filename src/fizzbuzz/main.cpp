#include <iostream>

#include "solution.cpp"

int main() {
  uint32_t n;
  std::cin >> n;

  Solution solution;
  auto output = solution.fizzBuzz(n);

  for (auto s : output) {
    std::cout << s << std::endl;
  }

  return 0;
}
