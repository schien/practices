// https://leetcode.com/problems/valid-anagram/
// https://leetcode.com/problems/implement-strstr/
// https://leetcode.com/problems/group-anagrams/

#include <string>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>

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
    int strStr(string haystack, string needle) {
      const int sz_h = haystack.size();
      const int sz_n = needle.size();
      for (int i = 0; i < sz_h - sz_n + 1; ++i) {
        if (haystack.compare(i, sz_n, needle) == 0) {
          return i;
        }
      }
      return -1;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      array<char, 512> buf;
      array<int, 26> count;
      auto tag = [&buf, &count](const string& s) {
        const int sz = s.size();
        count.fill(0);
        for (char c:s) {
          ++count[c-'a'];
        }
        int b = 0;
        for (int i = 0; i < 26; ++i) {
          if (!count[i]) {
            continue;
          }
          const char c = 'a' + i;
          fill_n(buf.begin()+b, count[i], c);
          b+=count[i];
        }
        return string(buf.data(), sz);
      } ;

      const int sz = strs.size();
      unordered_map<string, vector<string>> table;
      for (int i = 0; i < sz; ++i) {
        const string& s = strs[i];
        table[tag(s)].emplace_back(s);
      }

      vector<vector<string>> result;
      for (auto& e:table) {
        result.emplace_back(move(e.second));
      }

      return result;
    }
};
