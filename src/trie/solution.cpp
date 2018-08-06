// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
#include <array>

using namespace std;

inline int idx(char c) {
  return c-'a';
}

class Trie {
  public:
    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      const int sz = word.size();
      Node* curr = &root;
      for (int i = 0; i < sz; ++i) {
        const auto ci = idx(word[i]);
        auto nxt = curr->next[ci];
        if (nxt) {
          curr = nxt;
        } else {
          nxt = new Node;
          curr = curr->next[ci] = nxt;
        }
      }
      curr->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      const int sz = word.size();
      Node* curr = &root;
      for (int i = 0; i < sz; ++i) {
        auto nxt = curr->next[idx(word[i])];
        if (!nxt) { return false; }
        curr = nxt;
      }
      return curr->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      const int sz = prefix.size();
      Node* curr = &root;
      for (int i = 0; i < sz; ++i) {
        auto nxt = curr->next[idx(prefix[i])];
        if (!nxt) { return false; }
        curr = nxt;
      }
      return true;
    }

    struct Node {
      bool end = false;
      array<Node*,26> next = {};
    };
    Node root;
};
