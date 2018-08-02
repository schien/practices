// https://leetcode.com/problems/rotate-image/
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// https://leetcode.com/problems/game-of-life/
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// https://leetcode.com/problems/spiral-matrix/

#include <vector>
#include <queue>
#include <tuple>

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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.empty()) {
        return false;
      }
      const int H = matrix.size();
      const int W = matrix[0].size();

      int i = 0;
      int j = W-1;

      while (j >= 0 && i < H) {
        const int n = matrix[i][j];
        if (n == target) {
          return true;
        }

        if (n > target) {
          --j;
        } else {
          ++i;
        }
      }
      return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
      if (board.empty()) {
        return;
      }
      const int H = board.size();
      const int W = board[0].size();

      auto is_live = [&board, H, W](int i, int j) {
        if (i < 0 || j < 0 || i >= H || j >= W) {
          return 0;
        }
        return board[i][j] & 1;
      };
      auto next_state = [&is_live](int i, int j) {
        int count = is_live(i-1, j-1) + is_live(i-1, j) + is_live(i-1, j+1)
          + is_live(i, j-1) + is_live(i, j+1)
          + is_live(i+1, j-1) + is_live(i+1, j) + is_live(i+1, j+1);
        if (count == 2) {
          return is_live(i, j);
        }
        if (count == 3) {
          return 1;
        }
        return 0;
      };
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          board[i][j] |= next_state(i, j) << 1;
        }
      }

      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          board[i][j] >>= 1;
        }
      }
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      const int sz = matrix.size();
      if (!sz || k < 1 || k > sz*sz) {
        return -1;
      }

      using e_t = tuple<int, int, int>; // (v,i,j)
      using c_t = vector<e_t>;
      auto cmp = [](const e_t& a, const e_t&b) {
        return get<0>(a) > get<0>(b);
      };

      priority_queue<e_t, c_t, decltype(cmp)> q(cmp);

      for (int i = 0; i < sz; ++i) {
        q.push({matrix[i][0], i, 0});
      }

      while (!q.empty()) {
        if (!--k) {
          return get<0>(q.top());
        }

        auto t = q.top();
        q.pop();

        const int i = get<1>(t);
        const int j = get<2>(t) + 1;
        if (j < sz) {
          q.push({matrix[i][j], i, j});
        }
      }

      return -1;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      if (matrix.empty() || matrix[0].empty()) {
        return {};
      }
      int b = 0, u = matrix.size();
      int l = 0, r = matrix[0].size();


      vector<int> result;
      result.reserve(u*r);
      int d = 0;
      while (b < u && l < r) {
        switch (d) {
          case 0:
            for (int i = l; i < r; ++i) {
              result.push_back(matrix[b][i]);
            }
            ++b;
            d = 1;
            break;
          case 1:
            --r;
            for (int i = b; i < u; ++i) {
              result.push_back(matrix[i][r]);
            }
            d = 2;
            break;
          case 2:
            --u;
            for (int i = r-1; i >= l; --i) {
              result.push_back(matrix[u][i]);
            }
            d = 3;
            break;
          case 3:
            for (int i = u-1; i >= b; --i) {
              result.push_back(matrix[i][l]);
            }
            ++l;
            d = 0;
            break;
        }
      }
      return result;
    }
};
