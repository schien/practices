// https://leetcode.com/problems/contains-duplicate/
// https://leetcode.com/problems/contains-duplicate-ii/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int x=[](){ std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

// time: O(nlogn) + O(n)
// space: O(1)
bool useSort(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  const int sz = nums.size();
  for (int i = 0; i < sz-1; ++i) {
    if (nums[i] == nums[i+1]) {
      return true;
    }
  }
  return false;
}

// time: O(n) * O(1)
// space: O(n)
bool useHashset(vector<int>& nums) {
  unordered_set<int> s(nums.size());
  return std::any_of(nums.begin(), nums.end(), [&s](int n) {
    return !s.insert(n).second;
  });
}

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      if (nums.size() < 2) {
        return false;
      }
      //return useHashset(nums);
      return useSort(nums);
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      const int sz = nums.size();
      unordered_map<int, int> table(sz);
      for (int i = 0; i < sz; ++i) {
        auto it = table.find(nums[i]);
        if (it != table.end() && (i - it->second <= k)) {
          return true;
        }
        table[nums[i]] = i;
      }
      return false;
    }
};
