// https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
      if (n < 1) {
        return -1;
      }

      long long l = 1;
      long long h = n;
      while (l < h) {
        long long m = (l+h) >> 1;
        if (isBadVersion(m)) {
          h = m;
        } else if (!isBadVersion(m+1)) {
          l = m+1;
        } else {
          return m+1;
        }
      }
      return h;
    }
};
