// https://leetcode.com/problems/gas-station/

#include <vector>

using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      if (gas.empty()) {
        return -1;
      }
      const int sz = gas.size();

      int i = 0;
      while (i < sz) {
        int tank = gas[i];
        int curr = i;
        for (int j = 0; j < sz; ++j) {

          tank -= cost[curr++];
          if (curr == sz) {
            curr = 0;
          }
          if (tank < 0) {
            break;
          }
          tank += gas[curr];
        }
        if (tank >= cost[curr]) {
          return i;
        }
        if (curr <= i) {
          return -1;
        }
        i = curr;
      }
      return -1;
    }
};
