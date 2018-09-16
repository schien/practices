// https://leetcode.com/problems/powx-n/
// https://leetcode.com/problems/self-dividing-numbers/
// https://leetcode.com/problems/nth-digit

#include <cstdlib>
#include <cstdint>
#include <vector>
#include <array>
#include <cmath>

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
    vector<int> selfDividingNumbers(int left, int right) {
      if (left > right || left <= 0) {
        return {};
      }

      vector<int> result;
      for (int i = left; i <= right; ++i) {
        array<bool, 10> digits;
        digits.fill(false);
        int n = i;
        while (n) { digits[n%10] = true; n/=10; }

        if (digits[0]) {
          continue;
        }

        bool divisible = true;
        for (int d = 1; d < 10; ++d) {
          if (digits[d] && (i%d)) {
            divisible = false;
            break;
          }
        }
        if (divisible) {
          result.emplace_back(i);
        }
      }
      return result;
    }
    int findNthDigit(int n) {
      if (n <= 0) {
        return -1;
      }
      int d = 1;
      long long c = 9;
      while (n > c*d) {
        n -= c*d;
        ++d;
        c *= 10;
      }

      int k = static_cast<int>(pow(10, d-1)) + ((n-1)/d);
      int i = d - ((n-1)%d);
      return (k% static_cast<int>(pow(10, i))) / static_cast<int>(pow(10, i-1));
    }
};
