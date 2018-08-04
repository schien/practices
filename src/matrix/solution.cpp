// https://leetcode.com/problems/rotate-image/
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// https://leetcode.com/problems/game-of-life/
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// https://leetcode.com/problems/spiral-matrix/
// https://leetcode.com/problems/number-of-islands/
// https://leetcode.com/problems/max-area-of-island/
// https://leetcode.com/problems/word-search/

#include <vector>
#include <queue>
#include <tuple>
#include <stack>

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
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty() || grid[0].empty()) {
        return 0;
      }
      const int H = grid.size();
      const int W = grid[0].size();
      vector<int> label(H*W, -1);
      vector<int> label_set;

      int next_l = 0;
      if (grid[0][0] != '0') {
        label[0] = next_l;
        label_set.push_back(next_l);
        ++next_l;
      }

      for (int i = 1; i < W; ++i) {
        if (grid[0][i] == '0') { continue; }

        if (grid[0][i-1] == '0') {
          label[i] = next_l;
          label_set.push_back(next_l);
          ++next_l;
        } else {
          label[i] = label[i-1];
        }
      }

      auto root = [&label_set](int l) {
        if (l < 0) { return l; }
        // traverse and flatten adjoint set
        while ( l != label_set[l] ) { l = label_set[l] = label_set[label_set[l]]; }
        return l;
      };

      for (int i = 1; i < H; ++i) {
        if (grid[i][0] != '0') {
          if (grid[i-1][0] == '0') {
            label[i*W] = next_l;
            label_set.push_back(next_l);
            ++next_l;
          } else {
            label[i*W] = label[(i-1)*W];
          }
        }
        for (int j = 1; j < W; ++j) {
          if (grid[i][j] == '0') { continue; }

          const int idx = i*W + j;
          const int ll = root(label[idx-1]);
          const int ul = root(label[idx-W]);

          if (ul < 0 || ll < 0) {
            int l = max(ul, ll);
            if (l < 0) {
              label_set.push_back(next_l);
              l = next_l++;
            }
            label[idx] = l;
          } else if (ul < ll) {
            label[idx] = ul;
            label_set[ll] = ul;
          } else if (ll < ul) {
            label[idx] = ll;
            label_set[ul] = ll;
          } else {
            label[idx] = ll;
          }
        }
      }

      const int l_sz = label_set.size();
      int count = 0;
      for (int i = 0; i < l_sz; ++i) {
        if (label_set[i] == i) { ++count; }
      }
      return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      if (grid.empty() || grid[0].empty()) {
        return 0;
      }
      const int H = grid.size();
      const int W = grid[0].size();

      auto count = [&grid, H, W](const int i, const int j) {
        stack<pair<int,int>> next;
        next.push({i,j});
        int area = 0;

        while(!next.empty()) {
          auto p = next.top();
          next.pop();
          const int x = p.first;
          const int y = p.second;
          if (!grid[x][y]) {
            continue;
          }
          ++area;
          grid[x][y] = 0;
          if (x > 0 && grid[x-1][y]) {
            next.push({x-1, y});
          }
          if (x < H-1 && grid[x+1][y]) {
            next.push({x+1, y});
          }
          if (y > 0 && grid[x][y-1]) {
            next.push({x, y-1});
          }
          if (y < W-1 && grid[x][y+1]) {
            next.push({x, y+1});
          }
        }
        return area;
      };

      int result = 0;
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          if (grid[i][j]) {
            result = max(result, count(i, j));
          }
        }
      }
      return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
      if (board.empty() || board[0].empty()) {
	return false;
      }

      const int H = board.size();
      const int W = board[0].size();
      const int S = word.size();

      if (!S || (S/W + (S%W?1:0)) > H) {
        return 0;
      }

      function<bool(int,int,int)> trace = [&trace, &board, &word, H, W, S](int i, int j, int s) {
	if (s == S) {
	  return true;
	}
	board[i][j] = tolower(board[i][j]);

	bool result = false;
	const auto nc = word[s];
	if (i > 0 && nc == board[i-1][j]) {
	  result = trace(i-1,j,s+1);
	}
	if (!result && i < H-1 && nc == board[i+1][j]) {
	  result = trace(i+1,j,s+1);
	}
	if (!result && j > 0 && nc == board[i][j-1]) {
	  result = trace(i,j-1,s+1);
	}
	if (!result && j < W-1 && nc == board[i][j+1]) {
	  result = trace(i, j+1,s+1);
	}

	board[i][j] = toupper(board[i][j]);
	return result;
      };

      for(int i = 0; i < H; ++i) {
	for (int j = 0; j < W; ++j) {
	  if (board[i][j] == word[0] && trace(i,j,1)) {
	    return true;
	  }
	}
      }
      return false;
    }
};
