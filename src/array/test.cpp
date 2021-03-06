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

TEST(FindPeakElementTest, empty) {
  Solution solution;
  vector<int> input{};
  EXPECT_EQ(-1, solution.findPeakElement(input));
}

TEST(FindPeakElementTest, tiny) {
  Solution solution;
  vector<int> input;

  for (auto n : {0, INT_MIN, INT_MAX}) {
    input = vector<int>{n};
    EXPECT_EQ(0, solution.findPeakElement(input));
  }

  input = vector<int>{INT_MIN, INT_MIN};
  EXPECT_EQ(1, solution.findPeakElement(input));
  input = vector<int>{INT_MIN, INT_MAX};
  EXPECT_EQ(1, solution.findPeakElement(input));
  input = vector<int>{INT_MAX, INT_MAX};
  EXPECT_EQ(1, solution.findPeakElement(input));
  input = vector<int>{INT_MAX, INT_MIN};
  EXPECT_EQ(0, solution.findPeakElement(input));
}

TEST(FindPeakElementTest, large) {
  Solution solution;
  vector<int> input(10000);

  for (int i = 0; i < 10000; ++i) {
    input[i] = 1;
    EXPECT_EQ(i, solution.findPeakElement(input));
    input[i] = 0;
  }
}

TEST(JumpGameTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_FALSE(solution.canJump(input));
}

TEST(JumpGameTest, simple) {
  Solution solution;
  vector<int> input(10, 1);
  EXPECT_TRUE(solution.canJump(input));

  input.emplace_back(0);
  for (int i = 0; i < input.size(); ++i) {
    swap(input[i], input[input.size()-1]);
    EXPECT_FALSE(solution.canJump(input));
  }
}

TEST(JumpGameTest, large) {
  Solution solution;
  vector<int> input(100000, 1);
  EXPECT_TRUE(solution.canJump(input));

  input.resize(200000);
  input[99999] = 99999;
  for (int i = 0; i < 100000; ++i) {
    swap(input[i], input[input.size()-1]);
    EXPECT_FALSE(solution.canJump(input));
  }
}

TEST(LargestNumberTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_EQ("", solution.largestNumber(input));
}

TEST(LargestNumberTest, zero) {
  Solution solution;
  vector<int> input(10, 0);

  EXPECT_EQ("0", solution.largestNumber(input));

  for (int i = 1; i < 100; ++i) {
    input[0] = i;
    EXPECT_EQ(to_string(i) + "000000000", solution.largestNumber(input));
  }
}

TEST(LargestNumberTest, example) {
  Solution solution;
  vector<int> input;

  input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ("9876543210", solution.largestNumber(input));

  input = {1, 10 ,100, 1000, 10000};
  EXPECT_EQ("110100100010000", solution.largestNumber(input));

  input = {1, 12, 122, 1222, 12222};
  EXPECT_EQ("122221222122121", solution.largestNumber(input));

  input = {121, 12};
  EXPECT_EQ("12121", solution.largestNumber(input));
}

TEST(MaxProductTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_EQ(0, solution.maxProduct(input));
}

TEST(MaxProductTest, zero) {
  Solution solution;
  vector<int> input{0};
  EXPECT_EQ(0, solution.maxProduct(input));

  input = {0, 0, -1};
  EXPECT_EQ(0, solution.maxProduct(input));

  input = {-1, 0, 0};
  EXPECT_EQ(0, solution.maxProduct(input));

  input = {-1, 0, 0};
  EXPECT_EQ(0, solution.maxProduct(input));

  input = {0, -1, 0};
  EXPECT_EQ(0, solution.maxProduct(input));

  input = {-1, 0, -1};
  EXPECT_EQ(0, solution.maxProduct(input));
}

TEST(MaxProductTest, non_zero) {
  Solution solution;
  vector<int> input{1, 2, 3, 1};
  EXPECT_EQ(6, solution.maxProduct(input));

  input = {1, 2, -1, -2, -3, 1, 1};
  EXPECT_EQ(6, solution.maxProduct(input));

  input = {3, -5, -1, -3, 2, 2};
  EXPECT_EQ(15, solution.maxProduct(input));

  input = {-1, -5, -2};
  EXPECT_EQ(10, solution.maxProduct(input));

  input = {-3, 1, -5, 1, -2};
  EXPECT_EQ(15, solution.maxProduct(input));

  input = {100, -1};
  EXPECT_EQ(100, solution.maxProduct(input));

  input = {10, 5, -1, 100};
  EXPECT_EQ(100, solution.maxProduct(input));
}

TEST(MaxProductTest, zero_separate) {
  Solution solution;
  vector<int> input{0};
  EXPECT_EQ(0, solution.maxProduct(input));

  for (int n : {1, 2, 3, 1}) {
    input.emplace_back(n);
  }
  EXPECT_EQ(6, solution.maxProduct(input));

  input.emplace_back(0);
  for (int n: {1, 2, -1, -2, -3, 1, 1}) {
    input.emplace_back(n);
  }
  EXPECT_EQ(6, solution.maxProduct(input));

  input.emplace_back(0);
  input.emplace_back(0);
  for (int n : {3, -5, -1, -3, 2, 2}) {
    input.emplace_back(n);
  }

  EXPECT_EQ(15, solution.maxProduct(input));

  input.emplace_back(0);
  input.emplace_back(0);
  input.emplace_back(0);
  for (int n : {-1, -5, -2}) {
    input.emplace_back(n);
  }
  EXPECT_EQ(15, solution.maxProduct(input));

  input.emplace_back(0);
  input.emplace_back(-100);
  input.emplace_back(0);
  for (int n : {-3, 1, -5, 1, -2}) {
    input.emplace_back(n);
  }
  EXPECT_EQ(15, solution.maxProduct(input));

  input.emplace_back(0);
  input.emplace_back(0);
  EXPECT_EQ(15, solution.maxProduct(input));
}

TEST(SearchRotateTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_EQ(-1, solution.search(input, 0));
}

TEST(SearchRotateTest, small) {
  Solution solution;
  vector<int> input { 1, 3, 5, 7, 9 };

  for (int r = 0; r < 5; ++r) {
    for (int i = 0; i <= 10; ++i) {
      if (!(i&1)) {
        EXPECT_EQ(-1, solution.search(input, i));
      } else {
        int expected = ((i>>1) + r)%5;
        EXPECT_EQ(expected, solution.search(input, i));
      }
    }
    input.insert(input.begin(), input.back());
    input.resize(5);
  }
}

TEST(SearchRangeTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_EQ((vector<int>{-1,-1}), solution.searchRange(input, 0));
}

TEST(SearchRangeTest, not_found) {
  Solution solution;
  vector<int> input {0};
  EXPECT_EQ((vector<int>{-1,-1}), solution.searchRange(input, -1));
  EXPECT_EQ((vector<int>{-1,-1}), solution.searchRange(input, 1));

  input = {0, 0};
  EXPECT_EQ((vector<int>{-1,-1}), solution.searchRange(input, -1));
  EXPECT_EQ((vector<int>{-1,-1}), solution.searchRange(input, 1));

  input = { 1, 3, 5, 7, 9 };
  for (int i = 0; i <= 10; i+=2) {
    EXPECT_EQ((vector<int>{-1,-1}), solution.searchRange(input, i));
  }
}

TEST(SearchRangeTest, found) {
  Solution solution;
  vector<int> input {0};
  EXPECT_EQ((vector<int>{0, 0}), solution.searchRange(input, 0));

  input = {0, 0};
  EXPECT_EQ((vector<int>{0, 1}), solution.searchRange(input, 0));

  input = { 1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 9, 9, 9, 9, 9 };
  EXPECT_EQ((vector<int>{0,0}), solution.searchRange(input, 1));
  EXPECT_EQ((vector<int>{1,2}), solution.searchRange(input, 3));
  EXPECT_EQ((vector<int>{3,5}), solution.searchRange(input, 5));
  EXPECT_EQ((vector<int>{6,9}), solution.searchRange(input, 7));
  EXPECT_EQ((vector<int>{10,14}), solution.searchRange(input, 9));
}

TEST(WiggleSortTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_NO_THROW(solution.wiggleSort(input));
}

TEST(WiggleSortTest, small) {
  Solution solution;
  vector<int> input{1};
  solution.wiggleSort(input);
  EXPECT_EQ(vector<int>{1}, input);

  input = {0, 1};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1}), input);

  input = {1, 0};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1}), input);

  input = {0, 1, 0};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1, 0}), input);

  input = {1, 0, 0};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1, 0}), input);

  input = {0, 0, 1};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1, 0}), input);

  input = {0, 0, 1, 1};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1, 0, 1}), input);

  input = {1, 1, 0, 0};
  solution.wiggleSort(input);
  EXPECT_EQ((vector<int>{0, 1, 0, 1}), input);
}

TEST(WiggleSortTest, large) {
  Solution solution;
  vector<int> input(100000);
  for (int i = 0; i < 100000; ++i) {
    input[i] = i;
  }
  auto verdict = [](vector<int>& nums) {
    const int sz = nums.size();
    for (int i = 0; i < sz-1; i+=2) {
      if (nums[i] >= nums[i+1]) {
        return false;
      }
    }

    for (int i = 1; i < sz-1; i+=2) {
      if (nums[i] <= nums[i+1]) {
        return false;
      }
    }

    return true;
  };

  for (int i = 0; i < 10; ++i) {
    solution.wiggleSort(input);
    EXPECT_TRUE(verdict(input));
    random_shuffle(input.begin(), input.end());
  }

  input.emplace_back(100000);
  for (int i = 0; i < 10; ++i) {
    solution.wiggleSort(input);
    EXPECT_TRUE(verdict(input));
    random_shuffle(input.begin(), input.end());
  }

  for (int i = 0; i < 49999; ++i) {
    input[i] = 50000;
  }
  for (int i = 0; i < 10; ++i) {
    solution.wiggleSort(input);
    EXPECT_TRUE(verdict(input));
    random_shuffle(input.begin(), input.end());
  }

  for (int i = 0; i < 49999; ++i) {
    input[i] = 0;
  }
  for (int i = 0; i < 10; ++i) {
    solution.wiggleSort(input);
    EXPECT_TRUE(verdict(input));
    random_shuffle(input.begin(), input.end());
  }

  for (int i = 0; i < 49999; ++i) {
    input[i] = 100000;
  }
  for (int i = 0; i < 10; ++i) {
    solution.wiggleSort(input);
    EXPECT_TRUE(verdict(input));
    random_shuffle(input.begin(), input.end());
  }

}

TEST(MaxConsecutiveOnesTest, empty) {
  Solution solution;
  vector<int> input;
  EXPECT_EQ(0, solution.findMaxConsecutiveOnes(input));
}

TEST(MaxConsecutiveOnesTest, example) {
  Solution solution;
  vector<int> input{0};

  EXPECT_EQ(0, solution.findMaxConsecutiveOnes(input));

  input = {1};
  EXPECT_EQ(1, solution.findMaxConsecutiveOnes(input));

  input = {1,1,0};
  EXPECT_EQ(2, solution.findMaxConsecutiveOnes(input));

  input = {0,1,1,1};
  EXPECT_EQ(3, solution.findMaxConsecutiveOnes(input));

  input = {0,1,1,1,1,0};
  EXPECT_EQ(4, solution.findMaxConsecutiveOnes(input));

  input = {0,1,1,1,1,1,0,1};
  EXPECT_EQ(5, solution.findMaxConsecutiveOnes(input));

  input = {0,1,1,1,1,1,0,1,1,1,1,1,1};
  EXPECT_EQ(6, solution.findMaxConsecutiveOnes(input));
}

TEST(MinCostClimbStairTest, boundary_condition) {
  Solution solution;
  vector<int> input;

  EXPECT_EQ(0, solution.minCostClimbingStairs(input));

  input={1000};
  EXPECT_EQ(0, solution.minCostClimbingStairs(input));

  input={1000, 2000};
  EXPECT_EQ(0, solution.minCostClimbingStairs(input));
}

TEST(MinCostClimbStairTest, small) {
  Solution solution;
  vector<int> input{0, 0, 0};

  EXPECT_EQ(0, solution.minCostClimbingStairs(input));

  input={0, 100, 100};
  EXPECT_EQ(100, solution.minCostClimbingStairs(input));

  input={100, 0, 100};
  EXPECT_EQ(0, solution.minCostClimbingStairs(input));

  input={0, 100, 0};
  EXPECT_EQ(0, solution.minCostClimbingStairs(input));
}

TEST(MinCostClimbStairTest, large) {
  Solution solution;
  vector<int> input(10000);

  for (int i = 0; i < 10000; ++i) {
    input[i] = 100;
    EXPECT_EQ(0, solution.minCostClimbingStairs(input));
    input[i] = 0;
  }

  input[0] = 100;
  for (int i = 2; i < 10000; ++i) {
    input[i] = 100;
    EXPECT_EQ(0, solution.minCostClimbingStairs(input));
    input[i] = 0;
  }

  input[9999] = 100;
  for (int i = 2; i < 9998; ++i) {
    input[i] = 100;
    EXPECT_EQ(0, solution.minCostClimbingStairs(input));
    input[i] = 0;
  }

  input[1] = 100;
  for (int i = 2; i < 9998; ++i) {
    input[i] = 100;
    EXPECT_EQ(100, solution.minCostClimbingStairs(input));
    input[i] = 0;
  }

  input[9998] = 100;
  for (int i = 2; i < 9997; ++i) {
    input[i] = 100;
    EXPECT_EQ(200, solution.minCostClimbingStairs(input));
    input[i] = 0;
  }
}

TEST(PeakIndexTest, small) {
  Solution solution;
  vector<int> input{0,1,0};
  EXPECT_EQ(1, solution.peakIndexInMountainArray(input));

  input = {0, 2, 1, 0};
  EXPECT_EQ(1, solution.peakIndexInMountainArray(input));

  input = {0, 1, 2, 0};
  EXPECT_EQ(2, solution.peakIndexInMountainArray(input));

  input = {0, 1, 2, 3, 0};
  EXPECT_EQ(3, solution.peakIndexInMountainArray(input));

  input = {0, 1, 3, 2, 0};
  EXPECT_EQ(2, solution.peakIndexInMountainArray(input));

  input = {0, 3, 2, 1, 0};
  EXPECT_EQ(1, solution.peakIndexInMountainArray(input));
}

TEST(CheckNonDecreasingTest, example) {
  Solution solution;
  vector<int> input{0};
  EXPECT_TRUE(solution.checkPossibility(input));

  vector<pair<vector<int>, bool>> examples = {
    {{0,1}, true},
    {{0,0}, true},
    {{1,0}, true},
    {{0,1,2}, true},
    {{0,2,1}, true},
    {{1,0,2}, true},
    {{1,2,0}, true},
    {{2,0,1}, true},
    {{2,1,0}, false},
    {{0,1,2,3}, true},
    {{0,1,3,2}, true},
    {{0,2,1,3}, true},
    {{0,2,3,1}, true},
    {{0,3,1,2}, true},
    {{0,3,2,1}, false},
    {{1,0,2,3}, true},
    {{1,0,3,2}, false},
    {{1,2,0,3}, true},
    {{1,2,3,0}, true},
    {{1,3,0,2}, false},
    {{1,3,2,0}, false},
    {{2,0,1,3}, true},
    {{2,0,3,1}, false},
    {{2,1,0,3}, false},
    {{2,1,3,0}, false},
    {{2,3,0,1}, false},
    {{2,3,1,0}, false},
    {{3,0,1,2}, true},
    {{3,0,2,1}, false},
    {{3,1,0,2}, false},
    {{3,1,2,0}, false},
    {{3,2,0,1}, false},
    {{3,2,1,0}, false},
  };

  for (auto& example : examples) {
    EXPECT_EQ(example.second, solution.checkPossibility(example.first));
  }
}

TEST(ThirdMaxTest, example) {
  Solution solution;
  vector<int> input{3,2,1};
  EXPECT_EQ(1, solution.thirdMax(input));

  input = {1,2};
  EXPECT_EQ(2, solution.thirdMax(input));

  input = {2,2,3,1};
  EXPECT_EQ(1, solution.thirdMax(input));
}

TEST(MaxSlidingWindowTest, example) {
  Solution solution;

  vector<int> input;
  int k = 0;
  EXPECT_EQ(vector<int>{}, solution.maxSlidingWindow(input, k));

  input = {1,3,-1,-3,5,3,6,7};
  k = 3;
  EXPECT_EQ((vector<int>{3,3,5,5,6,7}), solution.maxSlidingWindow(input, k));
}

TEST(MaxSlidingWindowTest, small) {
  Solution solution;

  vector<int> input;
  for (int i = 0; i < 100; ++i) {
    input.emplace_back(i);
  }
  EXPECT_EQ(input, solution.maxSlidingWindow(input, 1));
  EXPECT_EQ((vector<int>{99}), solution.maxSlidingWindow(input, 100));

  reverse(input.begin(), input.end());
  vector<int> expected;
  for (int i = 100; i > 0; --i) {
    expected.emplace_back(i-1);
    EXPECT_EQ(expected, solution.maxSlidingWindow(input, i));
  }
}

TEST(MinPairSumTest, empty) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(0, solution.arrayPairSum(input));
}

TEST(MinPairSumTest, small) {
  Solution solution;

  vector<int> input(20000);
  fill_n(input.begin(), 10000, 1);
  for (int i = 0; i < 100; ++i) {
    random_shuffle(input.begin(), input.end());
    EXPECT_EQ(5000, solution.arrayPairSum(input));
  }
}

TEST(SortByParityTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(vector<int>{}, solution.sortArrayByParity(input));

  for (int i = 0; i < 100; ++i) {
    input.emplace_back(i*2);
  }
  auto output = solution.sortArrayByParity(input);
  for (auto n : output) {
    EXPECT_FALSE(n&1);
  }

  for (int i = 0; i < 100; ++i) {
    input[i] = i*2+1;
  }
  output = solution.sortArrayByParity(input);
  for (auto n : output) {
    EXPECT_TRUE(n&1);
  }


  for (int i = 0; i < 100; ++i) {
    input[i] = i;
  }
  output = solution.sortArrayByParity(input);
  for (int i = 0; i < 50; ++i) {
    EXPECT_FALSE(output[i] & 1);
  }
  for (int i = 50; i < 100; ++i) {
    EXPECT_TRUE(output[i] & 1);
  }

}

TEST(PlaceFlowersTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_TRUE(solution.canPlaceFlowers(input, 0));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 1));

  input = {0};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {0,0};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {0,0,0};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_TRUE(solution.canPlaceFlowers(input, 2));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 3));

  input = {1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 0));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 1));

  input = {0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 0));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 1));
  input = {0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {0,0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_TRUE(solution.canPlaceFlowers(input, 2));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 3));

  input = {1,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 0));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 1));
  input = {1,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 0));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 1));
  input = {1,0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {1,0,0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {1,0,0,0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_TRUE(solution.canPlaceFlowers(input, 2));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 3));

  input = {0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 0));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 1));
  input = {0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 2));
  input = {0,0,0,0,1};
  EXPECT_TRUE(solution.canPlaceFlowers(input, 1));
  EXPECT_TRUE(solution.canPlaceFlowers(input, 2));
  EXPECT_FALSE(solution.canPlaceFlowers(input, 3));
}

TEST(UnsortedSubarrayTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(0, solution.findUnsortedSubarray(input));

  input = {1};
  EXPECT_EQ(0, solution.findUnsortedSubarray(input));
  input = vector<int>(5,1);
  EXPECT_EQ(0, solution.findUnsortedSubarray(input));


  input = {1,2,3,4,5};
  EXPECT_EQ(0, solution.findUnsortedSubarray(input));
  input = {5,1,2,3,4};
  EXPECT_EQ(5, solution.findUnsortedSubarray(input));
  input = {4,5,1,2,3};
  EXPECT_EQ(5, solution.findUnsortedSubarray(input));
  input = {3,4,5,1,2};
  EXPECT_EQ(5, solution.findUnsortedSubarray(input));

  input = {5,4,3,2,1};
  EXPECT_EQ(5, solution.findUnsortedSubarray(input));
  input = {1,5,4,3,2};
  EXPECT_EQ(4, solution.findUnsortedSubarray(input));
  input = {1,2,5,4,3};
  EXPECT_EQ(3, solution.findUnsortedSubarray(input));

  input = {1,4,2,3,5};
  EXPECT_EQ(3, solution.findUnsortedSubarray(input));
  input = {1,4,3,2,5};
  EXPECT_EQ(3, solution.findUnsortedSubarray(input));
  input = {1,3,4,2,5};
  EXPECT_EQ(3, solution.findUnsortedSubarray(input));

  input = {4,2,3,1,5};
  EXPECT_EQ(4, solution.findUnsortedSubarray(input));
  input = {4,2,1,3,5};
  EXPECT_EQ(4, solution.findUnsortedSubarray(input));
  input = {4,1,2,3,5};
  EXPECT_EQ(4, solution.findUnsortedSubarray(input));
}

TEST(CheckSubarraySumTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_FALSE(solution.checkSubarraySum(input, 0));
  input = {0};
  EXPECT_FALSE(solution.checkSubarraySum(input, 0));
  input = {1};
  EXPECT_FALSE(solution.checkSubarraySum(input, 1));

  input = {0, 0};
  EXPECT_TRUE(solution.checkSubarraySum(input, 0));
  EXPECT_TRUE(solution.checkSubarraySum(input, 1));

  input = {0, 1};
  EXPECT_FALSE(solution.checkSubarraySum(input, 0));
  EXPECT_TRUE(solution.checkSubarraySum(input, 1));

  input = {1,1,1,1,1};
  EXPECT_FALSE(solution.checkSubarraySum(input, 7));

  input = {23, 2, 4, 6, 7};
  EXPECT_TRUE(solution.checkSubarraySum(input, 6));
  input = {23, 2, 6, 4, 7};
  EXPECT_TRUE(solution.checkSubarraySum(input, 6));

  input = {1,1,1,1,1,1,1,1,1,1};
  for (int i = 11; i < 20; ++i) {
    random_shuffle(input.begin(), input.end());
    EXPECT_FALSE(solution.checkSubarraySum(input, i));
  }
}

TEST(SumRangeTest, example) {
  vector<int> input(100, 1);
  NumArray nums(input);

  for (int i = 0; i < 100; ++i) {
    for (int j = i; j < 100; ++j) {
      EXPECT_EQ(j-i+1, nums.sumRange(i, j));
    }
  }
}

TEST(StreamKthLargestTest, example) {
  KthLargest kth(1, {});
  EXPECT_EQ(1, kth.add(1));
  EXPECT_EQ(2, kth.add(2));
  EXPECT_EQ(2, kth.add(0));

  kth = KthLargest(2, {1,2});
  EXPECT_EQ(1, kth.add(0));
  EXPECT_EQ(2, kth.add(4));
  EXPECT_EQ(3, kth.add(3));

  kth = KthLargest(5, {0,2,4,6,8,10});
  EXPECT_EQ(4, kth.add(9));
  EXPECT_EQ(4, kth.add(1));
  EXPECT_EQ(5, kth.add(5));
  EXPECT_EQ(6, kth.add(7));
  EXPECT_EQ(6, kth.add(3));
}

TEST(SmallestRangeITest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(0, solution.smallestRangeI(input, 0));

  input = {99};
  EXPECT_EQ(0, solution.smallestRangeI(input, 0));
  EXPECT_EQ(0, solution.smallestRangeI(input, 1));

  input = {1,2,3,4,5};
  EXPECT_EQ(4, solution.smallestRangeI(input, 0));
  EXPECT_EQ(2, solution.smallestRangeI(input, 1));
  EXPECT_EQ(0, solution.smallestRangeI(input, 2));
  EXPECT_EQ(0, solution.smallestRangeI(input, 3));
}

TEST(GroupSizeXTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_FALSE(solution.hasGroupsSizeX(input));

  input = {1};
  EXPECT_FALSE(solution.hasGroupsSizeX(input));

  input = {1,2};
  EXPECT_FALSE(solution.hasGroupsSizeX(input));

  input = {1,1};
  EXPECT_TRUE(solution.hasGroupsSizeX(input));

  input = {1,1,1};
  EXPECT_TRUE(solution.hasGroupsSizeX(input));

  input = {1,1,2};
  EXPECT_FALSE(solution.hasGroupsSizeX(input));

  input = {1,1,2,2,2};
  EXPECT_FALSE(solution.hasGroupsSizeX(input));

  input = {1,1,2,2,2,2};
  EXPECT_TRUE(solution.hasGroupsSizeX(input));

  input = {1,1,1,1,2,2,2,2,2,2};
  EXPECT_TRUE(solution.hasGroupsSizeX(input));

  input.clear();
  for (int i = 0; i < 100; ++i) {
    input.push_back(i);
    input.push_back(i);
  }
  EXPECT_TRUE(solution.hasGroupsSizeX(input));

  input.push_back(100);
  EXPECT_FALSE(solution.hasGroupsSizeX(input));
  input.push_back(100);
  EXPECT_TRUE(solution.hasGroupsSizeX(input));
  input.push_back(100);
  EXPECT_FALSE(solution.hasGroupsSizeX(input));
  input.push_back(100);
  EXPECT_TRUE(solution.hasGroupsSizeX(input));
}

TEST(KdiffPairTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(0, solution.findPairs(input, 0));

  input = {1};
  EXPECT_EQ(0, solution.findPairs(input, 0));

  for (int i = 0; i < 10; ++i) {
    input.emplace_back(1);
    EXPECT_EQ(1, solution.findPairs(input, 0));
  }

  input ={1,2,3,4,5};
  for (int i = 1; i <= 5; ++i) {
    EXPECT_EQ(5-i, solution.findPairs(input, i));
    EXPECT_EQ(0, solution.findPairs(input, -i));
  }

  reverse(input.begin(), input.end());
  for (int i = 1; i <= 5; ++i) {
    EXPECT_EQ(5-i, solution.findPairs(input, i));
  }

  for (int i = 1; i < 5; ++i) {
    input.emplace_back(i);
  }
  for (int i = 1; i <= 5; ++i) {
    EXPECT_EQ(5-i, solution.findPairs(input, i));
  }

  input = {3, 1, 4, 1, 5};
  EXPECT_EQ(2, solution.findPairs(input, 2));

  input = {1, 3, 1, 5, 4};
  EXPECT_EQ(1, solution.findPairs(input, 0));
}

TEST(ThreeSumTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ((vector<vector<int>>{}), solution.threeSum(input));

  for (int i = 0; i < 10; ++i) {
    input.emplace_back(i);
    EXPECT_EQ((vector<vector<int>>{}), solution.threeSum(input));
  }

  input = {0,1,-1};
  EXPECT_EQ((vector<vector<int>>{{-1,0,1}}), solution.threeSum(input));

  for (int i = 0; i < 10; ++i) {
    input.emplace_back(1);
    EXPECT_EQ((vector<vector<int>>{{-1,0,1}}), solution.threeSum(input));
  }

  for (int i = 0; i < 10; ++i) {
    input.emplace_back(-1);
    EXPECT_EQ((vector<vector<int>>{{-1,0,1}}), solution.threeSum(input));
  }

  input.emplace_back(0);
  EXPECT_EQ((vector<vector<int>>{{-1,0,1}}), solution.threeSum(input));
  for (int i = 0; i < 10; ++i) {
    input.emplace_back(0);
    EXPECT_EQ((vector<vector<int>>{{-1,0,1},{0,0,0}}), solution.threeSum(input));
  }

  input = {-1, 0, 1, 2, -1, -4};
  EXPECT_EQ((vector<vector<int>>{{-1, -1, 2},{-1, 0, 1}}), solution.threeSum(input));
}

TEST(FirstMissingPositiveTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(1, solution.firstMissingPositive(input));

  input = {1,2,3,4,5,6,7,8,9};
  EXPECT_EQ(10, solution.firstMissingPositive(input));
  input = {1,1};
  EXPECT_EQ(2, solution.firstMissingPositive(input));
  input = {1,2,0};
  EXPECT_EQ(3, solution.firstMissingPositive(input));
  input = {3,4,-1,1};
  EXPECT_EQ(2, solution.firstMissingPositive(input));
  input = {7,8,9,11,12};
  EXPECT_EQ(1, solution.firstMissingPositive(input));
}

TEST(MonotonicTest, example) {
  Solution solution;

  vector<int> input{1,2,2,3};
  EXPECT_TRUE(solution.isMonotonic(input));

  input = {6,5,4,4};
  EXPECT_TRUE(solution.isMonotonic(input));

  input = {1,3,2};
  EXPECT_FALSE(solution.isMonotonic(input));

  input = {1,2,4,5};
  EXPECT_TRUE(solution.isMonotonic(input));

  input = {1,1,1};
  EXPECT_TRUE(solution.isMonotonic(input));
}

TEST(SortByParityIITest, example) {
  Solution solution;
  vector<int> input;

  EXPECT_EQ(vector<int>{}, solution.sortArrayByParityII(input));

  for (int i = 0; i < 1000; ++i) {
    input.emplace_back(i);
  }

  auto verify = [](const vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      EXPECT_EQ(i&1, nums[i]&1);
    }
  };
  for (int i = 0; i < 1000; ++i) {
    random_shuffle(input.begin(), input.end());
    verify(solution.sortArrayByParityII(input));
  }
}

TEST(PivotIndexTest, example) {
  Solution solution;

  vector<int> input;
  EXPECT_EQ(-1, solution.pivotIndex(input));

  for (int i = -5; i < 5; ++i) {
    input = {i};
    EXPECT_EQ(0, solution.pivotIndex(input));
  }

  input = {1, 7, 3, 6, 5, 6};
  EXPECT_EQ(3, solution.pivotIndex(input));

  input = {1, 2, 3};
  EXPECT_EQ(-1, solution.pivotIndex(input));

  input = vector<int>(10001);
  EXPECT_EQ(0, solution.pivotIndex(input));

  for (int k = 0; k < 100; ++k) {
    for (int i = 0; i < 5000; ++i) {
      input[i] = input[i+5001] = static_cast<int>(2000*rand() - 1000);
    }
    input[5000] = static_cast<int>(2000*rand() - 1000);
    EXPECT_EQ(5000, solution.pivotIndex(input));
  }
}

TEST(FairCandySwapTest, example) {
  Solution solution;

  vector<int> A;
  vector<int> B;
  EXPECT_EQ(vector<int>{}, solution.fairCandySwap(A, B));

  A = {1};
  B = {1};
  EXPECT_EQ((vector<int>{1,1}), solution.fairCandySwap(A, B));

  A = {1, 1};
  B = {1};
  EXPECT_EQ((vector<int>{}), solution.fairCandySwap(A, B));

  A = {1, 2};
  B = {1, 1};
  EXPECT_EQ((vector<int>{}), solution.fairCandySwap(A, B));

  A = {1,1};
  B = {2,2};
  EXPECT_EQ((vector<int>{1,2}), solution.fairCandySwap(A, B));

  A = {1,2};
  B = {2,3};
  EXPECT_EQ((vector<int>{1,2}), solution.fairCandySwap(A, B));

  A = {2};
  B = {1,3};
  EXPECT_EQ((vector<int>{2,3}), solution.fairCandySwap(A, B));

  A = {1,2,5};
  B = {2,4};
  EXPECT_EQ((vector<int>{5,4}), solution.fairCandySwap(A, B));

  A = {8,73,2,86,32};
  B = {56,5,67,100,31};
  EXPECT_EQ((vector<int>{2,31}), solution.fairCandySwap(A, B));
}

}
