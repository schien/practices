// https://leetcode.com/problems/intersection-of-two-arrays/
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <vector>
#include <unordered_set>
#include <unordered_map>

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
};
