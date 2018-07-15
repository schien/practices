// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36

#include <unordered_map>
#include <vector>

using namespace std;

static unordered_map<int, int> answer;

static int get_cycle(int n) {
  if (answer[n]) {
    return answer[n];
  }

  int result = 0;

  vector<int> seq;
  seq.push_back(n);

  while (n != 1) {
    if (n & 1) {
      n = 3*n + 1;
    } else {
      n >>= 1;
    }
    if (result = answer[n], result) {
      break;
    }
    seq.push_back(n);
  }

  result += seq.size();
  for (int i = 0; i < seq.size(); ++i) {
    answer[seq[i]] = result - i;
  }
  return result;
}

static int get_max_cycle(int s, int e) {
  int result = 0;
  for (int i = s; i <= e; ++i) {
    result = max(result, get_cycle(i));
  }
  return result;
}

class Solution {
  public:
    int maxCycle(int i, int j) {
      return get_max_cycle(min(i, j), max(i, j));
    }
};
