#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(ContainsDuplicateTest, empty_list) {
  vector<int> empty;
  Solution solution;
  EXPECT_FALSE(solution.containsDuplicate(empty));
}

TEST(ContainsDuplicateTest, one_element) {
  vector<int> input { 1 };
  Solution solution;
  EXPECT_FALSE(solution.containsDuplicate(input));
}

TEST(ContainsDuplicateTest, dup) {
  vector<int> input { 1, 2, 1 };
  Solution solution;
  EXPECT_TRUE(solution.containsDuplicate(input));
}

TEST(ContainsDuplicateTest, no_dup) {
  vector<int> input { 1, 2, 3 };
  Solution solution;
  EXPECT_FALSE(solution.containsDuplicate(input));
}

TEST(ContainsDuplicateTest, dup_large) {
  vector<int> input;
  input.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    input.push_back(i);
  }
  input[1000000-1] = 0;

  Solution solution;
  EXPECT_TRUE(solution.containsDuplicate(input));
}

TEST(ContainsDuplicateTest, no_dup_large) {
  vector<int> input;
  input.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    input.push_back(i);
  }

  Solution solution;
  EXPECT_FALSE(solution.containsDuplicate(input));
}

}
