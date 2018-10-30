// https://leetcode.com/problems/employee-importance/

#include <vector>
#include <unordered_map>

using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
      unordered_map<int,Employee*> idx_table;
      for (auto emp : employees) {
        idx_table[emp->id] = emp;
      }

      vector<Employee*> q{idx_table[id]};
      int result = 0;
      for (size_t i = 0; i < q.size(); ++i) {
        if (!q[i]) { continue; }

        result += q[i]->importance;
        for (auto sub : q[i]->subordinates) {
          q.emplace_back(idx_table[sub]);
        }
      }
      return result;
    }
};
