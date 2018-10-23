//https://leetcode.com/problems/assign-cookies/

#include <vector>

using namespace std;

class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      if (g.empty() || s.empty()) {
        return 0;
      }

      sort(g.begin(), g.end());
      sort(s.begin(), s.end());

      const int sz = g.size();
      int i = 0;
      int count = 0;
      for (auto cookie : s) {
        if (g[i] <= cookie) {
          ++count;
          if (++i >= sz) {
            break;
          }
        }
      }
      return count;
    }
};
