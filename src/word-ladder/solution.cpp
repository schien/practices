#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> ws(wordList.begin(), wordList.end());

    if (ws.find(endWord) == ws.end()) {
      return 0;
    }

    const int sz = beginWord.size();

    int step = 1;
    unordered_set<string> curr {beginWord};
    unordered_set<string> target {endWord};
    ws.erase(beginWord);
    ws.erase(endWord);

    // bi-directional bfs
    while (!curr.empty() && !target.empty()) {
      ++step;
      unordered_set<string> next;
      for (auto w : curr) {
        // permute next possible string
        for (int i = 0; i < sz; ++i) {
          auto oc = w[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c == oc) {continue;}
            w[i] = c;
            // target found
            if (target.find(w) != target.end()) {
              return step;
            }
            // add valid next step and remove it from dictionary
            auto it = ws.find(w);
            if (it != ws.end()) {
              next.insert(w);
              ws.erase(it);
            }
          }
          w[i] = oc;
        }
      }
      curr.swap(next);
      // always try direction with smaller set of next steps
      if (curr.size() > target.size()) {
        curr.swap(target);
      }
    }

    return 0;
  }
};
