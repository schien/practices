// https://leetcode.com/problems/intersection-of-two-arrays/

#include <vector>
#include <unordered_set>

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
};
