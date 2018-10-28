//https://leetcode.com/problems/baseball-game/

#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
  public:
    int calPoints(vector<string>& ops) {
      vector<int> scores;
      for (auto& op : ops) {
        if (op == "C") {
          if (!scores.empty()) {
            scores.resize(scores.size()-1);
          }
        } else if (op == "D") {
          if (!scores.empty()) {
            scores.push_back(scores.back()*2);
          }
        } else if (op == "+") {
          if (scores.size() >= 2) {
            scores.push_back(scores.back() + scores[scores.size()-2]);
          }
        } else {
          scores.push_back(stoi(op,nullptr));
        }
      }
      return accumulate(scores.begin(), scores.end(), 0);
    }
};
