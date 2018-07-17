#include <iostream>

#include "solution.cpp"

int main() {
  Solution solution;

  int n;
  std::cin >> n;
  while (n--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << solution.relation(a, b) << '\n';
  }
  return 0;
}
