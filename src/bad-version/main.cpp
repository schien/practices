#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

static int bad_version = 0;

bool isBadVersion(int version) {
  return version >= bad_version;
}

int main() {
  int n = next<int>();
  bad_version = next<int>();

  Solution solution;
  std::cout << solution.firstBadVersion(n) << std::endl;

  return 0;
}
