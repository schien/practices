// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static void iterative(TreeNode* n, vector<int>& result) {
  while (n) {
    if (!n->left) {
      result.push_back(n->val);
      n = n->right;
    } else {
      TreeNode* right_most = n->left;
      while (right_most->right && right_most->right != n) {
        right_most = right_most->right;
      }
      if (right_most->right) {
        right_most->right = nullptr;
        result.push_back(n->val);
        n = n->right;
      } else {
        right_most->right = n;
        n = n->left;
      }
    }
  }
}

static void recursive(TreeNode* n, vector<int>& result) {
  if (!n) {
    return;
  }

  recursive(n->left, result);
  result.push_back(n->val);
  recursive(n->right, result);
}

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;
      //recursive(root, result);
      iterative(root, result);
      return result;
    }
};
