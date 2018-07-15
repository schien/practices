#include "gtest/gtest.h"
#include <algorithm>

#include "solution.cpp"

namespace {

TEST(ACM3nPlus1Test, one) {
  Solution solution;
  EXPECT_EQ(1, solution.maxCycle(1, 1));
}

TEST(ACM3nPlus1Test, example) {
  auto getCycle = [](int n) {
    int cycle = 1;
    while (n != 1) {
      if (n & 1) {
        n = 3*n + 1;
      } else {
        n >>= 1;
      }
      ++cycle;
    }
    return cycle;
  };

  auto gen = [&getCycle]() {
    static int g = 0;
    return getCycle(++g);
  };

  std::vector<int> table(20);
  std::generate(table.begin(), table.end(), gen);

  Solution solution;

  for (int i = 1; i < 20; ++i) {
    EXPECT_EQ(table[i-1], solution.maxCycle(i, i));
  }

  EXPECT_EQ(*std::max_element(table.begin(), table.end()), solution.maxCycle(1, 20));
}

}
