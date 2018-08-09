// https://leetcode.com/problems/course-schedule/

#include <vector>
#include <functional>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

static bool buttum_up(int numCourses, vector<pair<int, int>>& prerequisites) {
  enum class State{
    N, F, T
  };
  vector<State> traversed(numCourses, State::N);
  vector<vector<int>> dep(numCourses);
  for (auto &p:prerequisites) {
    dep[p.first].emplace_back(p.second);
  }

  function<bool(int)> dfs = [&dfs, &traversed, &dep](int i) {
    switch (traversed[i]) {
      case State::F:
        return true;
      case State::T:
        return false;
      case State::N:
      default:
        traversed[i] = State::T;
        for (auto n : dep[i]) {
          if (!dfs(n)) {
            return false;
          }
        }
        traversed[i] = State::F;
        return true;
    }
  };
  for (int i = 0; i < numCourses; ++i) {
    if (!dfs(i)) {
      return false;;
    }
  }
  return true;
}

static bool top_down(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<int> indegree(numCourses);
  vector<vector<int>> out(numCourses);

  for (auto &p:prerequisites) {
    ++indegree[p.first];
    out[p.second].emplace_back(p.first);
  }

  int count = 0;
  queue<int> q;
  for (int i = 0; i < numCourses; ++i) {
    if (!indegree[i]) {
      q.push(i);
      ++count;
    }
  }

  while (!q.empty()) {
    for (auto n : out[q.front()]) {
      if(!--indegree[n]) {
        q.push(n);
        ++count;
      }
    }
    q.pop();
  }

  return count == numCourses;
}

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    return buttum_up(numCourses, prerequisites);
    //return top_down(numCourses, prerequisites);
  }
};
