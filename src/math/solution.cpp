// https://leetcode.com/problems/powx-n/

#include <cstdlib>
#include <cstdint>

using namespace std;

class Solution {
  public:
    double myPow(double x, int n) {
      bool neg = n < 0;

      long long m = llabs(static_cast<long long>(n));
      double result = 1.0;
      for (int i = 0; i < 32; ++i) {
        uint32_t mask = 1<<i;
        if (mask > m) {
          break;
        }
        if (m & mask) {
          result *= x;
        }
        x *= x;
      }

      if (neg) {
        return 1.0 / result;
      }

      return result;
    }
};
