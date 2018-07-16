//https://leetcode.com/problems/4sum-ii/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    // time: O(n^2) + O(n^2)
    // space: O(n^2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, int> t1(A.size()*B.size());
      for (auto n1 : A) {
	for (auto n2 : B){
	  ++t1[n1+n2];
	}
      }

      int result = 0;
      for (auto n1 : C) {
	for (auto n2 : D) {
	  auto iter = t1.find(-n1-n2);
	  if (iter != t1.end()) {
	    result += iter->second;
	  }
	}
      }

      return result;
    }
};
