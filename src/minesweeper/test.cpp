#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(MinesweeperTest, small) {
  Solution solution;

  vector<string> input {
    "*...",
    "....",
    ".*..",
    "....",
  };
  solution.resolveField(input);
  vector<string> expect {
    "*100",
    "2210",
    "1*10",
    "1110",
  };
  EXPECT_EQ(expect, input);

  input = {
    "**...",
    ".....",
    ".*...",
  };
  solution.resolveField(input);
  expect = {
    "**100",
    "33200",
    "1*100",
  };

  input = {
    "*****",
    "*****",
    "*****",
  };
  solution.resolveField(input);
  expect = {
    "*****",
    "*****",
    "*****",
  };

  input = {
    ".....",
    ".....",
    ".....",
  };
  solution.resolveField(input);
  expect = {
    "00000",
    "00000",
    "00000",
  };

  input = {
    "***",
    "*.*",
    "***",
  };
  solution.resolveField(input);
  expect = {
    "***",
    "*8*",
    "***",
  };
}

}
