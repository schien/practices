// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
      array<int, 26> table;
      table.fill(0);
      const int sz = s.size();
      if (sz != t.size()) {
        return false;
      }

      for (int i = 0; i < sz; ++i) {
        table[s[i] - 'a'] += 1;
        table[t[i] -'a'] -= 1;
      }

      return all_of(table.begin(), table.end(), [](int n) { return !n; });
    }
};
