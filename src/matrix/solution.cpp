// https://leetcode.com/problems/rotate-image/

#include <vector>

using namespace std;

void direct(vector<vector<int>>& matrix) {
  const int n = matrix.size();

  for (int u=0, d=n-1; u<d; ++u, --d) {
    for (int i=0; i < d-u; ++i) {
      swap( matrix[u][u+i], matrix[u+i][d]);
      swap( matrix[u][u+i], matrix[d-i][u]);
      swap(matrix[d][d-i], matrix[d-i][u]);
    }
  }
}

void two_step(vector<vector<int>>& matrix) {
  // step 1: mirror upside down
  reverse(matrix.begin(), matrix.end());

  // step 2: mirror 45 degree
  const int n = matrix.size();
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      direct(matrix);
      //two_step(matrix);
    }
};
