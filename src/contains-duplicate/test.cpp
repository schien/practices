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

TEST(NearbyDuplicateTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, INT_MAX));
}

TEST(NearbyDuplicateTest, boundary_condition) {
  Solution solution;
  vector<int> input{0};
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, INT_MAX));

  input = {1, 1};
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 0));
}

TEST(NearbyDuplicateTest, small) {
  Solution solution;
  vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, INT_MAX));

  input.emplace_back(0);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 9));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 10));

  input.emplace_back(2);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 8));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 9));

  input.emplace_back(4);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 7));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 8));

  input.emplace_back(6);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 6));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 7));

  input.emplace_back(8);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 5));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 6));

  input.emplace_back(0);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 4));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 5));

  input.emplace_back(4);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 3));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 4));

  input.emplace_back(8);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 2));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 3));

  input.emplace_back(4);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 1));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 2));

  input.emplace_back(4);
  EXPECT_FALSE(solution.containsNearbyDuplicate(input, 0));
  EXPECT_TRUE(solution.containsNearbyDuplicate(input, 1));
}

}
