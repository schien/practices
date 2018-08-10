// https://leetcode.com/problems/course-schedule/
// https://leetcode.com/problems/course-schedule-ii/

#include <vector>
#include <functional>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

static bool buttum_up(int numCourses, vector<pair<int, int>>& prerequisites, vector<int>& result) {
  enum class State{
    N, F, T
  };
  vector<State> traversed(numCourses, State::N);
  vector<vector<int>> dep(numCourses);
  for (auto &p:prerequisites) {
    dep[p.first].emplace_back(p.second);
  }

  function<bool(int)> dfs = [&dfs, &traversed, &dep, &result](int i) {
    traversed[i] = State::T;
    for (auto n : dep[i]) {
      switch(traversed[n]) {
        case State::N:
          if (!dfs(n)) {
            return false;
          }
          break;
        case State::T:
          return false;
        default:
          break;
      }
    }
    traversed[i] = State::F;
    result.emplace_back(i);
    return true;
  };
  for (int i = 0; i < numCourses; ++i) {
    if (traversed[i] == State::N && !dfs(i)) {
      return false;;
    }
  }
  return true;
}

static bool top_down(int numCourses, vector<pair<int, int>>& prerequisites, vector<int>& result) {
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
    result.emplace_back(q.front());
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
    vector<int> result;
    return buttum_up(numCourses, prerequisites, result);
    //return top_down(numCourses, prerequisites, result);
  }
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
    if (buttum_up(numCourses, prerequisites, result)) {
    //if (top_down(numCourses, prerequisites, result)) {
      return result;
    }
    return {};
  }
};
