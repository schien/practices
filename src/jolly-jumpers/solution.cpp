#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool isJolly(vector<int>& nums) {
      const uint32_t N = nums.size();
      if (N <= 1) {
        return true;
      }

      unordered_set<uint64_t> table;
      table.reserve(N);

      int prev = nums[0];
      for (int i = 1; i < N; ++i) {
        int curr = nums[i];
        uint64_t diff = labs(long(prev)-curr);
        if (!diff || diff >= N || !table.insert(diff).second) {
          return false;
        }
        prev = curr;
      }
      return true;
    }
};
