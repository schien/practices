// https://leetcode.com/problems/intersection-of-two-arrays/
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// https://leetcode.com/problems/top-k-frequent-elements/

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
};
