// https://leetcode.com/problems/intersection-of-two-arrays/
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// https://leetcode.com/problems/top-k-frequent-elements/
// https://leetcode.com/problems/product-of-array-except-self/
// https://leetcode.com/problems/permutations/
// https://leetcode.com/problems/find-the-duplicate-number/
// https://leetcode.com/problems/subsets/
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// https://leetcode.com/problems/increasing-triplet-subsequence/
// https://leetcode.com/problems/longest-increasing-subsequence/
// https://leetcode.com/problems/sort-colors/
// https://leetcode.com/problems/find-peak-element/
// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/largest-number/
// https://leetcode.com/problems/maximum-product-subarray/
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// time: O(n)
// space: O(n)*2
bool increasingTriplet_dp(vector<int>& nums) {
  const int sz = nums.size();
  vector<int> left_mins(nums);
  vector<int> right_maxs(nums);

  // compute min between n_first ~ n_i and max between n_i ~ n_last
  for (int i = 1; i < sz; ++i) {
    left_mins[i] = min(left_mins[i], left_mins[i-1]);
    right_maxs[sz-i-1] = max(right_maxs[sz-i], right_maxs[sz-i-1]);
  }

  // check if any i that min_i < n_i < max_i
  for (int i = 1; i < sz-1; ++i) {
    if (left_mins[i] < nums[i] && right_maxs[i] > nums[i]) {
      return true;
    }
  }

  return false;
}

// time: O(n)
// space: O(1)
bool increasingTriplet_patient_sort(vector<int>& nums) {
  // we only need two decks since we are look for
  // any increasing sequence more than 3 elements
  int d1 = INT_MAX, d2 = INT_MAX;
  for (auto n : nums) {
    if (n <= d1) {
      d1 = n;
    } else if (n <= d2) {
      d2 = n;
    } else {
      return true;
    }
  }
  return false;
}

// time: O(n)
// space: O(1)
int findPeakElement_linear_search(vector<int>& nums) {
  const int sz = nums.size();
  int prev = INT_MIN;
  for (int i = 0; i < sz; ++i) {
    if (nums[i] < prev) {
      return i-1;
    }
    prev = nums[i];
  }
  return sz-1;
}

// time: avg O(log n), worst case O(nlogn)
// space: O(1)
int findPeakElement_binary_search(vector<int>& nums) {
  if (nums.empty()) {
    return -1;
  }

  function<int(int,int)> worker = [&nums, &worker](int l, int h) {
    while (l < h) {
      int m = (l+h)>>1;

      if (nums[m] > nums[m+1]) {
        h = m;
      } else if (nums[m] < nums[m+1]) {
        l = m+1;
      } else {
        auto l_peak = worker(l, m);
        auto r_peak = worker(m+1, h);
        return (nums[l_peak] > nums[r_peak]?l_peak:r_peak);
      }
    }
    return l;
  };

  return worker(0, nums.size()-1);
}

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
    int findKthLargest(vector<int>& nums, int k) {
      int l = 0;
      int h = nums.size()-1;
      k = nums.size()-k;

      while (l < h) {
        // pick random pivot
        int p = rand()%(h-l+1) + l;
        swap(nums[h], nums[p]);

        // partition according to pivot
        int i = l, j = h-1;
        const int pivot = nums[h];
        while (i <= j) {
          if (nums[i]<=pivot) {
            ++i;
          } else {
            swap(nums[i], nums[j--]);
          }
        }
        swap(nums[i], nums[h]);

        if (k == i) {
          // kth idx is determined
          break;
        } else if (k < i) {
          // continue in lower partition
          h = i-1;
        } else {
          // continue in higher partition
          l = i+1;
        }
      }
      return nums[k];
    }
    bool increasingTriplet(vector<int>& nums) {
      //return increasingTriplet_dp(nums);
      return increasingTriplet_patient_sort(nums);
    }
    // time: O(nlogn)
    // space: O(n)
    int lengthOfLIS(vector<int>& nums) {
      const int sz = nums.size();
      if (!sz) {
        return 0;
      }
      vector<int> seq{nums[0]};
      seq.reserve(sz);
      for (int i = 1; i < sz; ++i) {
        const int n = nums[i];
        auto j = lower_bound(seq.begin(), seq.end(), n);
        if (j != seq.end()) {
          *j = n;
        } else {
          seq.emplace_back(n);
        }
      }
      return seq.size();
    }
    // time: O(n)
    // space: O(1)
    void sortColors(vector<int>& nums) {
      const int sz = nums.size();
      int i = 0; // current
      int j = 0; // next zero
      int k = sz-1; // next two

      while (i <= k) {
        switch(nums[i]) {
          case 0:
            swap(nums[i++], nums[j++]);
            break;
          case 1:
            ++i;
            break;
          case 2:
            swap(nums[i], nums[k--]);
            break;
        }
      }
    }
    int findPeakElement(vector<int>& nums) {
      return findPeakElement_linear_search(nums);
      return findPeakElement_binary_search(nums);
    }
    bool canJump(vector<int>& nums) {
      if (nums.empty()) {
        return false;
      }
      const int sz = nums.size();
      int mx = 0;
      int curr = 0;
      while (curr <= mx) {
        mx = max(mx, curr + nums[curr]);
        if (mx >= sz-1) {
          return true;
        }
        ++curr;
      }
      return false;
    }
    string largestNumber(vector<int>& nums) {
      vector<string> ns;
      int zero_count = 0;
      int max_length = 0;
      for (auto n:nums) {
        if (!n) { ++zero_count; ++max_length; continue; }
        auto s = to_string(n);
        max_length += s.size();
        ns.emplace_back(s);
      }

      sort(ns.begin(), ns.end(), [](const string& lhs, const string& rhs){
          // fast path
          const int minz = min(lhs.size(),rhs.size());
          for (int i = 0; i < minz; ++i) {
            if (lhs[i] == rhs[i]) {
              continue;
            }
            return lhs[i] > rhs[i];
          }

          // slow path
          return (lhs+rhs) > (rhs+lhs);
      });

      string result;
      result.reserve(max_length);
      for (auto& s: ns) {
        result += s;
      }

      if (zero_count) {
        if (result.empty()) {
          result.push_back('0');
        } else {
          result.append(zero_count, '0');
        }
      }

      return result;
    }
    int maxProduct(vector<int>& nums) {
      if (nums.empty()) {
        return 0;
      }

      // max product for non-zero subarray
      auto submax = [&nums](int b, int e) {
        if (e-b == 1) {
          return nums[b];
        }

        int sub = 1;
        int left = 1;
        int left_max = nums[b];
        for (int i = b; i < e; ++i) {
          sub *= nums[i];
          left_max = max(left_max, sub);
          if (left > 0) {
            left *= nums[i];
          }
        }
        return max(left_max, sub/left);
      };

      const int sz = nums.size();
      int result = nums[0];
      bool zero = false;

      int i = 0;
      while (i < sz) {
        if (!nums[i]) {
          zero = true;
          ++i;
          continue;
        }
        int j = i+1;
        while (j < sz && nums[j]) ++j;
        if (j < sz) { zero = true; }
        result = max(result, submax(i, j));
        i = j+1;
      }

      if (zero && result < 0) {
        return 0;
      }
      return result;
    }
    int search(vector<int>& nums, int target) {
      if (nums.empty()) { return -1; }

      const int sz = nums.size();
      if (target == nums[0]) { return 0; }
      if (target == nums[sz-1]) { return sz-1; }

      int l = 0;
      int h = sz-1;
      while (l < h) {
        const int m = (l+h)>>1;
        const auto vm = nums[m];

        if (target == vm) { return m; }

        const auto vl = nums[l];
        const auto vh = nums[h];
        if ((vl < vm && (target > vl && target < vm)) ||
            (vl > vm && !(target > vm && target < vh))) {
          h = m-1;
          if (target == nums[h]) { return h; }
        } else {
          l = m+1;
          if (target == nums[l]) { return l; }
        }
      }
      return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.empty() || target < nums.front() || target > nums.back()) {
        return {-1, -1};
      }
      const int sz = nums.size();
      int l = 0;
      // search for the first index that nums[i] >= target;
      int count = sz;
      while (count) {
        int step = count>>1;
        if (nums[l+step] < target) {
          l += step+1;
          count -= step+1;
          if (nums[l] >= target) {
            break;
          }
        } else {
          count = step;
        }
      }
      if (l == sz || nums[l] != target) {
        return {-1,-1};
      }
      int h = l;
      // search for the first index that nums[i] > target;
      count = sz-l;
      while (count) {
        int step = count>>1;
        if (nums[h+step] == target) {
          h += step+1;
          count -= step+1;
          if (nums[h] != target) {
            break;
          }
        } else {
          count = step;
        }
      }
      return {l, h-1};
    }
};
