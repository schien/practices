#include "gtest/gtest.h"
#include <algorithm>
#include <set>

#include "solution.cpp"

namespace {

TEST(ArrayUniqueIntersectTest, empty) {
  Solution solution;
  vector<int> empty;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(vector<int>{}, solution.intersection(empty, empty));
  EXPECT_EQ(vector<int>{}, solution.intersection(ones, empty));
  EXPECT_EQ(vector<int>{}, solution.intersection(empty, ones));
}

TEST(ArrayUniqueIntersectTest, same) {
  Solution solution;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(vector<int>{1}, solution.intersection(ones, ones));
}

TEST(ArrayUniqueIntersectTest, no_intersection) {
  Solution solution;

  vector<int> ones(1000000, 1);
  vector<int> zeros(1000000, 0);

  EXPECT_EQ(vector<int>{}, solution.intersection(ones, zeros));
}

TEST(ArrayUniqueIntersectTest, subset) {
  Solution solution;

  vector<int> all;
  vector<int> odds;

  all.reserve(1000000);
  odds.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    all.push_back(i);
    if (i&1) {
      odds.push_back(i);
    }
  }

  EXPECT_EQ(odds, solution.intersection(all, odds));
}

TEST(ArrayMultiIntersectTest, empty) {
  Solution solution;
  vector<int> empty;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(vector<int>{}, solution.intersect(empty, empty));
  EXPECT_EQ(vector<int>{}, solution.intersect(ones, empty));
  EXPECT_EQ(vector<int>{}, solution.intersect(empty, ones));
}

TEST(ArrayMultiIntersectTest, same) {
  Solution solution;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(ones, solution.intersect(ones, ones));
}

TEST(ArrayMultiIntersectTest, no_intersection) {
  Solution solution;

  vector<int> ones(1000000, 1);
  vector<int> zeros(1000000, 0);

  EXPECT_EQ(vector<int>{}, solution.intersect(ones, zeros));
}

TEST(ArrayMultiIntersectTest, subset) {
  Solution solution;

  vector<int> all;
  vector<int> double_all;

  all.reserve(1000000);
  double_all.reserve(1000000*2);
  for (int i = 0; i < 1000000; ++i) {
    all.push_back(i);
    double_all.push_back(i);
    double_all.push_back(i);
  }


  EXPECT_EQ(all, solution.intersection(all, double_all));
  EXPECT_EQ(all, solution.intersection(double_all, all));
}

TEST(TopKFrequentTest, large) {
  unordered_set<int> expected;
  vector<int> input;
  input.reserve(2001*1000);
  for (int i = 1; i <= 2000; ++i) {
    expected.insert(i);
    for (int j = 0; j < i; ++j) {
      input.push_back(i);
    }
  }

  Solution solution;

  auto output = solution.topKFrequent(input, 1);
  EXPECT_EQ(vector<int>{2000}, output);

  output = solution.topKFrequent(input, 1000);
  unordered_set<int> expected_1k;
  for (int i = 1001; i <= 2000; ++i) {
    expected_1k.insert(i);
  }
  EXPECT_EQ(expected_1k, unordered_set<int>(output.begin(), output.end()));
}

TEST(ProductExceptSelfTest, zeros) {
  vector<int> input(1000000);
  Solution solution;
  EXPECT_EQ(input, solution.productExceptSelf(input));
}

TEST(ProductExceptSelfTest, ones) {
  vector<int> input(1000000, 1);
  Solution solution;
  EXPECT_EQ(input, solution.productExceptSelf(input));
}

TEST(ProductExceptSelfTest, negative_1) {
  vector<int> input(1000000, -1);
  Solution solution;
  EXPECT_EQ(input, solution.productExceptSelf(input));

  input = vector<int>(999999, -1);
  EXPECT_EQ(vector<int>(999999, 1), solution.productExceptSelf(input));
}

TEST(PermutationTest, empty) {
  vector<int> empty;
  Solution solution;
  EXPECT_EQ(vector<vector<int>>{{}}, solution.permute(empty));
}

TEST(PermutationTest, one) {
  vector<int> input{1};
  Solution solution;
  EXPECT_EQ(vector<vector<int>>{input}, solution.permute(input));
}

TEST(PermutationTest, small) {
  vector<int> input{1, 2, 3, 4, 5};
  Solution solution;

  int expected_size = 1;
  for (int i = input.size(); i > 1; --i) {
    expected_size *= i;
  }
  auto output = solution.permute(input);

  EXPECT_EQ(expected_size, output.size());

  set<vector<int>> values;
  for (auto vec : output) {
    values.insert(vec);
  }

  set<vector<int>> expected_values;
  do {
    expected_values.insert(input);
  } while (next_permutation(input.begin(), input.end()));

  EXPECT_EQ(expected_values, values);
}

TEST(PermutationTest, large) {
  vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
  Solution solution;

  int expected_size = 1;
  for (int i = input.size(); i > 1; --i) {
    expected_size *= i;
  }
  auto output = solution.permute(input);

  EXPECT_EQ(expected_size, output.size());

  set<vector<int>> values;
  for (auto vec : output) {
    values.insert(vec);
  }

  set<vector<int>> expected_values;
  do {
    expected_values.insert(input);
  } while (next_permutation(input.begin(), input.end()));

  EXPECT_EQ(expected_values, values);
}

TEST(PermutationTest, unordered) {
  vector<int> input{3, 4, 2, 1};
  Solution solution;

  int expected_size = 1;
  for (int i = input.size(); i > 1; --i) {
    expected_size *= i;
  }
  auto output = solution.permute(input);

  EXPECT_EQ(expected_size, output.size());

  set<vector<int>> values;
  for (auto vec : output) {
    values.insert(vec);
  }

  set<vector<int>> expected_values;
  do {
    expected_values.insert(input);
  } while (next_permutation(input.begin(), input.end()), --expected_size);

  EXPECT_EQ(expected_values, values);
}

}
