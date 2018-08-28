// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <vector>
#include <stack>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
  public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
    }
};

class Solution {
  public:
    vector<int> preorder(Node* root) {
      if (!root) {
        return {};
      }

      vector<int> result;

      stack<Node*> st;
      st.push(root);

      while(!st.empty()) {
        const auto n = st.top();
        st.pop();
        result.emplace_back(n->val);

        for (int i = n->children.size()-1; i >= 0; --i) {
          if (n->children[i]) {
            st.push(n->children[i]);
          }
        }
      }
      return result;
    }
};
