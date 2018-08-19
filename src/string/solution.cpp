// https://leetcode.com/problems/valid-anagram/
// https://leetcode.com/problems/implement-strstr/
// https://leetcode.com/problems/group-anagrams/
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// https://leetcode.com/problems/word-break/
// https://leetcode.com/problems/decode-ways/
// https://leetcode.com/problems/palindrome-partitioning/
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// https://leetcode.com/problems/basic-calculator-ii/

#include <string>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <functional>
#include <stack>
#include <numeric>

using namespace std;

static bool isPalindrome(const string& s, const int l, const int h) {
  int i = l, j = h;
  while (i < j) {
    if (s[i++] != s[j--]) {
      return false;
    }
  }
  return true;
}

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
    int romanToInt(string s) {
      const int sz = s.size();

      auto special = [sz, &s](const int base, const char five, const char ten, int& i) {
        if (i+1 < sz) {
          if (s[i+1] == five) {
            ++i;
            return base * 4;
          } else if (s[i+1] == ten) {
            ++i;
            return base * 9;
          }
        }
        return base;
      };

      int result = 0;
      int i = 0;
      while (i < sz) {
        switch (s[i]) {
          case 'I':
            result += special(1, 'V', 'X', i);
            break;
          case 'V':
            result += 5;
            break;
          case 'X':
            result += special(10, 'L', 'C', i);
            break;
          case 'L':
            result += 50;
            break;
          case 'C':
            result += special(100, 'D', 'M', i);
            break;
          case 'D':
            result += 500;
            break;
          case 'M':
            result += 1000;
            break;
          default:
            return -1;
        }
        ++i;
      }

      return result;
    }
    vector<string> letterCombinations(string digits) {
      if (digits.empty()) {
        return {};
      }

      static array<string, 10> table {{
        "", "", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"
      }};

      vector<string> result;

      function<void(string&, const int)> worker = [&worker, &result](string& prefix, const int i) {
        const char d = prefix[i];
        const auto& s = table[d-'0'];
        for (auto c:s) {
          prefix[i] = c;
          if (i) {
            worker(prefix, i-1);
          } else {
            result.push_back(prefix);
          }
        }
        prefix[i] = d;
      };
      worker(digits, digits.size()-1);
      return result;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      if (s.empty() || wordDict.empty()) {
        return false;
      }
      const int sz = s.size();
      vector<bool> dp(sz+1);
      dp[0] = true;

      for (int i = 1; i <= sz; ++i) {
        for (auto& w:wordDict) {
          const int wsz = w.size();
          const int prev = i-wsz;
          if (prev < 0 || !dp[prev]) {
            continue;
          }
          bool matched = true;
          for (int j = 0; j < wsz; ++j) {
            if (w[j] != s[prev+j]) {
              matched = false;
              break;
            }
          }
          if (matched) {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[sz];
    }
    int numDecodings(string s) {
      if (s.empty()) { return 0; }

      const int sz = s.size();

      int prev = 1, curr = 0, next = 0;
      for (int i = 0; i < sz; ++i) {
        if (s[i] != '0') {
          curr += prev;
        }

        if (i < sz-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
          next = prev;
        }

        prev = curr;
        curr = next;
        next = 0;

        if (!curr && !prev) {
          return 0;
        }
      }
      return prev;
    }
    vector<vector<string>> partition(string s) {
      function<vector<vector<string>>(const int)> worker = [&s, &worker](const int e) {
        if (e <= 0) { return vector<vector<string>>{{}}; }

        vector<vector<string>> result;
        for (int i = 0; i < e; ++i) {
          if (!isPalindrome(s, i, e-1)) {
            continue;
          }
          auto sub = worker(i);
          for (auto& vec: sub) {
            vec.emplace_back(s.substr(i, e-i));
            result.emplace_back(move(vec));
          }
        }
        return result;
      };
      return worker(s.size());
    }
    int evalRPN(vector<string>& tokens) {
      auto isOperator = [](const string& s) {
        if (s.size() != 1) {
          return false;
        }
        switch(s[0]) {
          case '+':
          case '-':
          case '*':
          case '/':
            return true;
          default:
            return false;
        }
      };
      stack<int> val;
      for (auto &s: tokens) {
        if (isOperator(s)) {
          if (val.size() < 2) {
            throw runtime_error("not enough operand for " + s);
          }
          int rhs = val.top();
          val.pop();
          int lhs = val.top();
          val.pop();
          switch(s[0]) {
            case '+':
              val.push(lhs+rhs);
              break;
            case '-':
              val.push(lhs-rhs);
              break;
            case '*':
              val.push(lhs*rhs);
              break;
            case '/':
              val.push(lhs/rhs);
              break;
            default:
              break;
          }
        } else {
          val.push(stoi(s));
        }
      }

      if (val.size() != 1) {
        throw runtime_error("not a complete expression");
      }

      return val.top();
    }
    int calculate(string s) {
      const int sz = s.size();

      vector<int> operands;
      char op = '+';
      int i = 0;
      while (i < sz) {
        auto c = s[i];

        if (isdigit(c)) {
          int num = c-'0';
          int j = i+1;
          while (j < sz && isdigit(s[j])) {
            num = num*10 + (s[j]-'0');
            ++j;
          }
          switch (op) {
            case '+': operands.emplace_back(num); break;
            case '-': operands.emplace_back(-num); break;
            case '*': operands.back() *= num; break;
            case '/': operands.back() /= num; break;
            default: break;
          }
          i = j;
        } else {
          switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
              op = c;
              break;
            default:
              break;
          }
          ++i;
        }
      }

      return accumulate(operands.begin(), operands.end(), 0);
    }
};
