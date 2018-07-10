// https://leetcode.com/problems/house-robber/

#include <vector>
#include <functional>

using namespace std;

// time: O(n)
// space: O(1)
static int dp(vector<int>& nums) {
  const int sz = nums.size();
  if (!sz) {
    return 0;
  }
  if (sz > 1) {
    nums[1] = max(nums[0], nums[1]);
  }
  for (int i = 2; i < sz; ++i) {
    nums[i] = max(nums[i-1], nums[i]+nums[i-2]);
  }
  return nums[sz-1];
}

// time: O(n)
// space: O(1) + O(n){stack}
static int recursion_with_memorization(vector<int>& nums, int i) {
  vector<int> table(nums.size(), -1);

  std::function<int(int)> worker = [&table, &nums, &worker](int i) {
    if (i < 0) {
      return 0;
    }
    if (!i) {
      return nums[0];
    }
    if (table[i] < 0) {
      table[i] = max(nums[i] + worker(i-2),
                     worker(i-1));
    }

    return table[i];
  };
  return worker(i);
}

// time: O(2^n)
// space: O(1) + O(n){stack}
static int recursion(vector<int>& nums, int i) {
  if (i < 0) {
    return 0;
  }
  if (!i) {
    return nums[0];
  }

  return max(nums[i] + recursion(nums, i-2),
             recursion(nums, i-1));
}

class Solution {
  public:
    int rob(vector<int>& nums) {
      //return recursion(nums, nums.size()-1);
      //return recursion_with_memorization(nums, nums.size()-1);
      return dp(nums);
    }
};
