// https://leetcode.com/problems/coin-change/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      if (coins.empty() || !amount) {
        return amount?-1:0;
      }

      const int sz = coins.size();
      sort(coins.begin(), coins.end(), greater<int>());

      function<int(const int, const int)> worker = [&worker, &coins, &sz](const int i, int amount) {
        if (amount < 0) {
          return -1;
        }
        const int coin = coins[i];
        int max = amount / coin;
        int r = amount % coin;
        if (!r) {
          return max;
        }

        if (i == sz -1 && r) {
          return -1;
        }

        int min = -1;
        while (max >= 0) {
          int estimate = r/coins[i+1] + ((r%coins[i+1])?1:0);
          if (min > 0 && min <= estimate + max) {
            break;
          }
          int rest = worker(i+1, r);
          if (rest > 0) {
            const int curr = rest + max;
            if (min < 0 || curr < min) {
              min = curr;
            }
          }

          r += coin;
          --max;
        }
        return min;
      };

      return worker(0, amount);
    }

};
