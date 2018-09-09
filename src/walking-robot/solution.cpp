// https://leetcode.com/problems/walking-robot-simulation/

#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

enum DIR {
  N = 0, E = 1, S = 2, W = 3
};

static int dx[4] = {0, 1, 0, -1};
static int dy[4] = {1, 0, -1, 0};

uint64_t to_hash(int x, int y) {
  uint64_t h = static_cast<uint32_t>(x);
  h <<= 32;
  h |= static_cast<uint32_t>(y);
  return h;
}

class Solution {
  public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      unordered_set<uint64_t> obs;
      for (auto& v:obstacles) {
        obs.insert(to_hash(v[0], v[1]));
      }
      int x = 0;
      int y = 0;
      int dir = N;
      int ans = 0;

      for (auto cmd : commands) {
        if (cmd == -2) {
          dir = (dir+3) % 4;
        } else if (cmd == -1) {
          dir = (dir+1) % 4;
        } else {
          const int diff_x = dx[dir];
          const int diff_y = dy[dir];
          while (cmd--) {
            int next_x = x + diff_x;
            int next_y = y + diff_y;
            if (obs.find(to_hash(next_x, next_y)) != obs.end()) {
              break;
            }
            x = next_x;
            y = next_y;
          }
          ans = max (ans, x*x + y*y);
        }
      }
      return ans;
    }
};
