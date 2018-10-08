// https://leetcode.com/problems/is-graph-bipartite/

#include <vector>

using namespace std;

class Solution {
  public:
    bool isBipartite(vector<vector<int>>& graph) {
      const int sz = graph.size();
      vector<int> color(sz, 0); // 0 = not assigned, 1 = A, -1 = B

      vector<int> q;
      q.reserve(sz);
      size_t i = 0;
      for (int n = 0; n < sz; ++n) {
        if (color[n]) {continue;}

        q.emplace_back(n);
        color[n] = 1;

        while (i < q.size()) {
          const int curr = q[i++];
          const int my_color = color[curr];
          for (int adj : graph[curr]) {
            if (!color[adj]) {
              color[adj] = -my_color;
              q.emplace_back(adj);
            } else if (color[adj] != -my_color) {
              return false;
            }
          }
        }
      }
      return true;
    }
};
