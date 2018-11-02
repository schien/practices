// https://leetcode.com/problems/guess-number-higher-or-lower/

int guess(int num);

class Solution {
  public:
    int guessNumber(int n) {
      if (n <= 0) { return -1; }

      long long l = 1;
      long long h = n;
      while (l < h) {
        const long long m = (l+h)/2;
        switch (guess(m)) {
          case 0:
            return m;
          case -1:
            h = m-1;
            break;
          case 1:
            l = m+1;
            break;
        }
      }
      return l;
    }
};
