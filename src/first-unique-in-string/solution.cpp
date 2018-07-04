// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <string>
#include <array>
#include <iostream>

using namespace std;

int x=[](){ std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
  public:
    int firstUniqChar(string s) {
      array<int, 26> idx;
      idx.fill(INT_MAX);

      const int sz = s.size();
      for (int i = 0; i < sz; ++i) {
	const int index = s[i] - 'a';
	idx[index] = (i < idx[index] ? i : -1);
      }

      int result = INT_MAX;
      for (int i = 0; i < 26; ++i) {
	if (idx[i] >= 0) {
	  result = min(result, idx[i]);
	}
      }
      return (result == INT_MAX ? -1 : result);
    }
};
