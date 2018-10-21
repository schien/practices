// https://leetcode.com/problems/happy-number/
// https://leetcode.com/problems/add-digits/
// https://leetcode.com/problems/ugly-number/
// https://leetcode.com/problems/perfect-squares/
// https://leetcode.com/problems/hamming-distance/
// https://leetcode.com/problems/valid-perfect-square/
// https://leetcode.com/problems/sum-of-square-numbers/
// https://leetcode.com/problems/perfect-number/
// https://leetcode.com/problems/excel-sheet-column-title/
// https://leetcode.com/problems/number-complement/
// https://leetcode.com/problems/binary-gap/
// https://leetcode.com/problems/reach-a-number/

#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int numSquares_recursive(int n) {
  if (!n) {
    return 0;
  }

  int result = INT_MAX;
  for (int i = 1; i*i <= n; ++i) {
    result = min(result, 1+numSquares_recursive(n-i*i));
  }
  return result;
}
int numSquares_dp(int n) {
  if (n <= 0) {
    return 0;
  }

  static vector<int> dp;
  const int sz = dp.size();
  if (n < sz) {
    return dp[n];
  }

  dp.resize(n+1);

  const int bound = (int)sqrt(n);
  int square = bound*bound;
  for (int i = bound; bound > 0 && !dp[square]; --i) {
    dp[square] = 1;
    square -= 2*i - 1;
  }
  for (int i = sz; i <= n; ++i) {
    if (dp[i]) {
      continue;
    }
    int result = INT_MAX;
    int remain = i - 1;
    for (int j = 1; remain > 0; ++j) {
      result = min(result, 1+dp[remain]);
      remain -= 2*j + 1;
    }
    dp[i] = result;
  }
  return dp[n];
}
int numSquares_math(int n) {
  //Lagrange's four-square theorem
  //every natural number can be represented by sum of 4 square value
  auto is_square = [](int n) {
    const int root = (int)sqrt(n);
    return n == root*root;
  };

  // check perfect square number
  if (is_square(n)) {
    return 1;
  }

  // check (8m+7)*4^k format
  int t = n;
  while (!(t&3)) { t >>= 2; }
  if ((t&7)==7) { return 4; }

  const int half = n>>1;
  int root = (int)sqrt(n);
  int remain = n - root*root;
  // check if can split into two square numbers
  while (remain <= half) {
    if (is_square(remain)) {
      return 2;
    }
    remain += ((root--)<<1) - 1;
  }
  return 3;
}
class Solution {
  public:
    bool isHappy(int n) {
      if (n <= 0) {
        return false;
      }

      auto digitsum = [](int n) {
        int sum = 0;
        while (n) {
          int d = n%10;
          n /= 10;
          sum += d*d;
        }
        return sum;
      };

      unordered_set<int> visited;
      while (n != 1 && visited.insert(n).second) {
        n = digitsum(n);
      }
      return n == 1;
    }
    int addDigits(int num) {
      auto digitsum = [](int n) {
        int sum = 0;
        while(n) {
          sum += n%10;
          n /= 10;
        }
        return sum;
      };

      while(num >= 10) {
        num = digitsum(num);
      }
      return num;
    }
    bool isUgly(int num) {
      if (num < 0) {
        return false;
      }
      while (num > 1 && num % 2 == 0) {
        num /= 2;
      }
      while (num > 1 && num%3 == 0) {
        num /= 3;
      }
      while (num > 1 && num%5 == 0) {
        num /= 5;
      }
      return num == 1;
    }
    int numSquares(int n) {
      //return numSquares_recursive(n);
      //return numSquares_dp(n);
      return numSquares_math(n);
    }
    int hammingDistance(int x, int y) {
      x ^= y;
      x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
      x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
      x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
      x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
      x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
      return x;
    }
    bool isPerfectSquare(int num) {
      int root = static_cast<int>(sqrt(num));
      return root*root == num;
    }
    bool judgeSquareSum(int c) {
      if (c < 0) {
        return false;
      }

      int i = 0;
      int j = static_cast<int>(sqrt(c));
      while (i <= j) {
        int v = i*i + j*j;
        if (c == v) {
          return true;
        } else if (c > v) {
          ++i;
        } else {
          --j;
        }
      }
      return false;
    }
    bool checkPerfectNumber(int num) {
      if (num <= 1) {
        return false;
      }

      int bound = static_cast<int>(sqrt(num));
      int sum = 1;
      for (int i = 2; i <= bound; ++i) {
        if (num%i == 0) {
          if (i*i == num) {
            sum += i;
          } else {
            sum += i + num/i;
          }
        }
      }
      return sum == num;
    }
    string convertToTitle(int n) {
      if (n <= 0) { return ""; }
      string result;
      while(n) {
        n--;
        const char c = 'A' + (n%26);
        result.append(1, c);
        n /= 26;
      }
      reverse(result.begin(), result.end());
      return result;
    }
    int findComplement(int num) {
      int tail = num;
      tail |= tail >> 1;
      tail |= tail >> 2;
      tail |= tail >> 4;
      tail |= tail >> 8;
      tail |= tail >> 16;
      return (~num) & tail;
    }
    int binaryGap(int N) {
      if (N <= 0) { return 0; }

      // skip tailing 0's
      --N;
      while (N&1) { N >>= 1; }

      int prev = 0;
      int mx = 0;
      for (int i = 0; N > 0; ++i, N>>=1) {
        if (N&1) {
          mx = max(mx, i-prev);
          prev = i;
        }
      }
      return mx;
    }
    int reachNumber(int target) {
      if (target < 0) { target = -target; }
      int step = 0;
      int sum = 0;
      while (sum < target) { sum += ++step; }
      if (((sum-target)&1) == 0) { return step; }
      if (step&1) { return step+2; }
      return step+1;
    }
};
