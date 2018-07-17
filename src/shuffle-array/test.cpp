#include "gtest/gtest.h"
#include <array>

#include "solution.cpp"

namespace {

TEST(ShuffleArrayTest, prove_random) {
  constexpr int sz = 3;
  std::array<array<int, sz>, sz> table;
  for (auto row : table) {
    row.fill(0);
  }

  vector<int> input(sz);
  for (int i = 0; i < sz; ++i) {
    input[i] = i;
  }

  Solution solution(input);

  for (int i = 0; i < 1000000; ++i) {
    auto output = solution.shuffle();
    for (int j = 0; j < sz; ++j) {
      ++table[j][output[j]];
    }

    EXPECT_EQ(input, solution.reset());
  }

  for (auto row : table) {
    for (auto n : row) {
      EXPECT_NE(0, n);
    }
  }
}

}
