// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <vector>
#include <stack>
#include <queue>

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
    vector<vector<int>> levelOrder(Node* root) {
      if (!root) { return {}; }

      queue<Node*> q{{root}};

      vector<vector<int>> result;
      while(!q.empty()) {
        const int sz = q.size();
        result.resize(result.size()+1);
        for (int i = 0; i < sz; ++i) {
          Node* n = q.front();
          q.pop();

          result.back().emplace_back(n->val);
          for (auto child: n->children) {
            if (child) {
              q.emplace(child);
            }
          }
        }
      }

      return result;
    }
    vector<int> postorder(Node* root) {
      if (!root) { return {}; }

      vector<int> result;
      stack<Node*> st;
      st.emplace(root);

      while (!st.empty()) {
        Node* n = st.top();
        st.pop();
        result.emplace_back(n->val);

        for (auto child:n->children) {
          st.emplace(child);
        }
      }
      reverse(result.begin(), result.end());
      return result;
    }
    int maxDepth(Node* root) {
      if (!root) {
        return 0;
      }
      int mx = 0;
      for (auto child : root->children) {
        mx = max(mx, maxDepth(child));
      }
      return mx+1;
    }
};
