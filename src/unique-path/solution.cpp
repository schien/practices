#include <vector>
#include <algorithm>

using namespace std;

// time: O(m*n)
// space: O(m)
int dp(const int m, const int n) {
  vector<unsigned long long> table(m, 1);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      table[j] += table[j-1];
    }
  }
  return static_cast<int>(table[m-1]);
}

// time: min(O(m), O(n))
// space: O(1)
int math(const int m, const int n) {
  // same as calculating the pascal triangle
  // use binomial combination
  // use min(m,n) to avoid overflow
  const int line = m+n-1;
  const int column = min(m, n)-1;
  unsigned long long result = 1;
  for (int i = 1; i <= column; ++i) {
    result = result * (line-i) / i;
  }
  return static_cast<int>(result);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
      //return dp(m, n);
      return math(m, n);
    }
};
