#include "gtest/gtest.h"

#include "solution.cpp"

#include <iostream>
namespace {

TEST(FizzBuzzTest, n_15) {
  Solution solution;
  auto output = solution.fizzBuzz(15);

  auto to_fizzbuzz_str = [](int i)->string{
    if (i % 3 == 0 && i % 5 == 0) {
      return "FizzBuzz";
    } else if (i % 3 == 0) {
      return "Fizz";
    } else if (i % 5 == 0) {
      return "Buzz";
    } else {
      return to_string(i);
    }
  };

  int i = 1;
  for (auto s : output) {
    EXPECT_EQ(to_fizzbuzz_str(i++), s);
  }
}

TEST(FizzBuzzTest, n_0) {
  Solution solution;
  auto output = solution.fizzBuzz(0);
  EXPECT_TRUE(output.empty());
}

TEST(FizzBuzzTest, n_1) {
  Solution solution;
  EXPECT_EQ(vector<string>{"1"}, solution.fizzBuzz(1));
}

}
