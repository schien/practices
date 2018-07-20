// https://leetcode.com/problems/intersection-of-two-arrays/
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// https://leetcode.com/problems/top-k-frequent-elements/
// https://leetcode.com/problems/product-of-array-except-self/
// https://leetcode.com/problems/permutations/
// https://leetcode.com/problems/find-the-duplicate-number/
// https://leetcode.com/problems/subsets/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> table;
      for (auto n : nums1) {
	table.insert(n);
      }
      vector<int> result;
      for (auto n : nums2) {
	auto iter = table.find(n);
	if (iter != table.end()) {
	  table.erase(iter);
	  result.push_back(n);
	}
      }
      return result;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int> table;
      for (auto n : nums1) {
	table[n] += 1;
      }
      for (auto n : nums2) {
	if (table[n]) {
	  table[n] -= 1;
	}
      }
      vector<int> result;
      for (auto n : nums1) {
	if (--table[n] < 0) {
	  result.push_back(n);
	}
      }
      return result;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
      for (auto n : nums) {
        ++freq[n];
      }

      auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
      };
      priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

      auto iter = freq.begin();
      int i = 0;
      while (iter != freq.end()) {
        if (i < k) {
          pq.push(*iter);
        } else if (iter->second > pq.top().second) {
          pq.pop();
          pq.push(*iter);
        }
        ++iter;
        ++i;
      }
      vector<int> result;
      result.reserve(k);
      for (int i = 0; i < k; ++i) {
        result.push_back(pq.top().first);
        pq.pop();
      }
      return result;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
      if (nums.empty()) {
	return {};
      }

      const int sz = nums.size();

      vector<int> result(sz, 1);
      // result'[i] = nums[i+1]*...*nums[sz-1]
      int right_product = nums[sz-1];
      for (int i = sz-2; i >= 0; --i) {
	result[i] = right_product;
	right_product *= nums[i];
      }

      // result[i] = (nums[0]*...*nums[i-1]) * (nums[i+1]*...*nums[sz-1])
      int left_product = nums[0];
      for (int i = 1; i < sz; ++i) {
	result[i] *= left_product;
	left_product *= nums[i];
      }
      return result;
    }
    vector<vector<int>> permute(vector<int>& nums) {
      const int sz = nums.size();
      vector<vector<int>> result;
      function<void(const int)> worker = [&worker, &nums, &result](const int i) {
        if (i <= 0) {
          result.push_back(nums);
          return;
        }

        worker(i-1);
        for (int j = 0; j < i; ++j) {
          swap(nums[i], nums[j]);
          worker(i-1);
          swap(nums[i], nums[j]);
        }
      };
      worker(sz-1);
      return result;
    }
    // time: O(n) + O(n)
    // space: O(1)
    int findDuplicate(vector<int>& nums) {
      // precondition: nums has N+1 elements, value range is [1, N]
      int result = -1;
      for (auto n : nums) {
	auto t = abs(n);
	if (nums[t] < 0) {
	  result = t;
	} else {
          // use nagative value in index i to remember value i exists.
	  nums[t] *= -1;
	}
      }

      // restore the input array
      for (size_t i = 0; i < nums.size(); ++i) {
	nums[i] = abs(nums[i]);
      }
      return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> result{{}};
      result.reserve(1<<nums.size());

      for (auto n : nums) {
        auto vec = result;
        for (auto& v : vec) {
          v.push_back(n);
        }
        result.insert(result.end(), vec.begin(), vec.end());
      }

      return result;
    }
};
