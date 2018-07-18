// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1130

#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    void resolveField(vector<string>& field) {
      if (field.empty() || field[0].empty()) {
        return;
      }

      const int h = field.size();
      const int w = field[0].size();
      vector<vector<int>> map;
      for (int i = 0; i < h; ++i) {
        map.emplace_back(w);
      }
      for (int i = 0; i < h; ++i) {
        auto& line = field[i];
        for (int j = 0; j < w; ++j) {
          if (line[j] != '*') {
            continue;
          }

          map[i][j] -= 10;
          int r = min(w, j+2);
          int d = min(h, i+2);
          for (int u = max(0, i-1); u<d; ++u) {
            for (int l = max(0, j-1); l<r; ++l) {
              ++map[u][l];
            }
          }
        }
      }

      for (int i = 0; i < h; ++i) {
        auto& line = field[i];
        for (int j = 0; j < w; ++j) {
          if (line[j] != '*') {
            line[j] = '0' + map[i][j];
          }
        }
      }
    }
};
