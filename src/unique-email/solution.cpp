// https://leetcode.com/problems/unique-email-addresses/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int numUniqueEmails(vector<string>& emails) {
      unordered_map<string, unordered_set<string>> table; // domain -> set(name)

      int count = 0;
      for (auto& email : emails) {
        auto addr = getCanonicalAddr(email);
        auto& names = table[addr.first];
        if (names.insert(addr.second).second) {
          ++count;
        }
      }
      return count;
    }
  private:
    pair<string,string> getCanonicalAddr(const string& email) {
      auto pos_at = email.find('@');

      string name;
      for (size_t i = 0; i < pos_at; ++i) {
        switch (email[i]) {
          case '+':
            i = pos_at;
          case '.':
            break;
          default:
            name.push_back(email[i]);
        }
      }

      return {email.substr(pos_at+1), name};
    }
};
