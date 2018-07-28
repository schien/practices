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

TEST(FindDuplicateTest, small) {
  vector<int> input(5);
  Solution solution;

  for (int i = 0; i < 4; ++i) {
    input[i] = i+1;
  }
  for (int i = 1; i < 5; ++i) {
    input[4] = i;
    EXPECT_EQ(i, solution.findDuplicate(input));
  }

  for(int i = 1; i < 5; ++i) {
    input[i] = i;
  }
  for (int i = 1; i < 5; ++i) {
    input[0] = i;
    EXPECT_EQ(i, solution.findDuplicate(input));
  }
}

TEST(FindDuplicateTest, large) {
  const int N = 1000000;
  vector<int> input(N);
  Solution solution;

  for (int i = 0; i < N-1; ++i) {
    input[i] = i+1;
  }
  for (int i = 1; i < 100; ++i) {
    auto dup = 1 + rand()%(N-1);
    input[N-1] = dup;
    EXPECT_EQ(dup, solution.findDuplicate(input));
  }

  for(int i = 1; i < N; ++i) {
    input[i] = i;
  }
  for (int i = 1; i < 100; ++i) {
    auto dup = 1 + rand()%(N-1);
    input[0] = dup;
    EXPECT_EQ(dup, solution.findDuplicate(input));
  }
}

TEST(SubsetTest, empty) {
  Solution solution;
  vector<int> input{};
  EXPECT_EQ(vector<vector<int>>{{}}, solution.subsets(input));
}

TEST(SubsetTest, one) {
  Solution solution;
  vector<int> input{1};
  EXPECT_EQ((vector<vector<int>>{{}, {1}}), solution.subsets(input));
}

TEST(SubsetTest, example) {
  Solution solution;
  vector<int> input{1,2,3};
  vector<vector<int>> expected{
    {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}
  };

  auto output = solution.subsets(input);

  EXPECT_EQ(expected.size(), output.size());

  for (auto& e : expected) {
    EXPECT_NE(output.end(), find(output.begin(), output.end(), e));
  }
}

TEST(LargestKthTest, small) {
  Solution solution;
  vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 1; i <= 10; ++i) {
    random_shuffle(input.begin(), input.end());
    EXPECT_EQ(i, solution.findKthLargest(input, 10-i+1));
  }
}

TEST(LargestKthTest, large) {
  Solution solution;
  vector<int> input(1000000);
  for (int i = 0; i < 1000000; ++i) {
    input[i] = i;
  }

  for (int i = 1; i <= 1000000; i*=10) {
    random_shuffle(input.begin(), input.end());
    EXPECT_EQ(1000000-i, solution.findKthLargest(input, i));
  }
}

TEST(IncreasingTripletTest, small) {
  Solution solution;
  vector<vector<int>> inputs {
    {}, {1}, {1, 2}
  };

  for (auto& input : inputs) {
    EXPECT_FALSE(solution.increasingTriplet(input));
  }

  inputs = {
    {1, 2, 3},
    {1000, 1, 2, 3},
    {1, 1000, 2, 3},
    {1, 2, 1000, 3},
    {1, 2, 3, 1000}
  };

  for (auto& input : inputs) {
    EXPECT_TRUE(solution.increasingTriplet(input));
  }

  inputs = {
    {3000, 2000, 1000},
    {1, 3000, 2000, 1000},
    {3000, 1, 2000, 1000},
    {3000, 2000, 1, 1000},
    {3000, 2000, 1, 1000, 1}
  };

  for (auto& input : inputs) {
    EXPECT_FALSE(solution.increasingTriplet(input));
  }
}

TEST(IncreasingTripletTest, large) {
  Solution solution;

  vector<int> input(1000);
  for (int i = 1; i < 1000; i+=2) {
    input[i] = 1000;
  }

  EXPECT_FALSE(solution.increasingTriplet(input));

  for (int i = 1; i < 999; ++i) {
    const auto tmp = input[i];
    input[i] = 1;
    EXPECT_TRUE(solution.increasingTriplet(input));
    input[i] = tmp;
  }

  input = vector<int>(1000000, 1000000);
  EXPECT_FALSE(solution.increasingTriplet(input));

  input[0] = 1;
  EXPECT_FALSE(solution.increasingTriplet(input));

  input[1000000-2] = 2;
  EXPECT_TRUE(solution.increasingTriplet(input));
}

TEST(LengthOfLISTest, large) {
  Solution solution;

  vector<int> input(1000);
  EXPECT_EQ(1, solution.lengthOfLIS(input));

  for (int i = 0; i < 1000; ++i) {
    input[i] = i;
  }
  EXPECT_EQ(1000, solution.lengthOfLIS(input));

  reverse(input.begin(), input.end());
  EXPECT_EQ(1, solution.lengthOfLIS(input));

  reverse(input.begin()+500, input.end());
  EXPECT_EQ(500, solution.lengthOfLIS(input));

  reverse(input.begin(), input.begin()+500);
  EXPECT_EQ(500, solution.lengthOfLIS(input));
}

TEST(SortColorsTest, empty) {
  Solution solution;
  vector<int> input;
  solution.sortColors(input);
  EXPECT_EQ(vector<int>{}, input);
}

TEST(SortColorsTest, same) {
  Solution solution;
  vector<int> input;

  for (auto n : {0,1,2}) {
    input = {n};
    solution.sortColors(input);
    EXPECT_EQ(vector<int>{n}, input);

    input = vector<int>(10, n);
    solution.sortColors(input);
    EXPECT_EQ(vector<int>(10, n), input);
  }
}

TEST(SortColorsTest, large) {
  Solution solution;
  vector<int> input(3000);
  fill_n(input.begin()+1000, 1000, 1);
  fill_n(input.begin()+2000, 1000, 2);


  for (int i = 0; i < 1000; ++i) {
    random_shuffle(input.begin(), input.end());
    solution.sortColors(input);

    EXPECT_TRUE(all_of(input.begin(), input.begin()+1000, [](int n){ return n == 0; }));
    EXPECT_TRUE(all_of(input.begin()+1000, input.begin()+2000, [](int n){ return n == 1; }));
    EXPECT_TRUE(all_of(input.begin()+2000, input.end(), [](int n){ return n == 2; }));
  }
}

}
