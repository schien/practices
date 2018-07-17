// https://leetcode.com/problems/shuffle-an-array/

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
  Solution(vector<int> nums)
    : nums_(nums) , result_(nums)
  {
  }

  vector<int> reset() {
    return nums_;
  }

  vector<int> shuffle() {
    for (int i = result_.size()-1; i > 0; --i) {
      swap(result_[i], result_[rand()%(i+1)]);
    }
    return result_;
  }
private:
  vector<int> nums_;
  vector<int> result_;
};
