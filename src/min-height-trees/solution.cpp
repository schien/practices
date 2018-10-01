// https://leetcode.com/problems/minimum-height-trees/
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    // construct adjacent list
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
    }

    // find all leave nodes
    vector<int> degree(n);
    vector<int> Q;
    Q.reserve(n);
    for (int i = 0; i < n; ++i) {
      degree[i] = adj[i].size();
      if (degree[i] <= 1) {
        Q.push_back(i);
      }
    }

    // bfs from all leave nodes
    size_t i = 0;
    while (n > 2) {
      const size_t len = Q.size();
      n -= len - i;

      for (; i < len; ++i) {
        for (auto neighbor : adj[Q[i]]) {
          if (--degree[neighbor] == 1) {
            Q.push_back(neighbor);
          }
        }
      }
    }

    vector<int> result;
    for (; i < Q.size(); ++i) {
      result.push_back(Q[i]);
    }
    return result;
  }
};
