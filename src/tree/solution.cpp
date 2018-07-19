// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <vector>
#include <functional>

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
    int kthSmallest(TreeNode* root, int k) {
      if (!root || k <= 0) {
        throw range_error("no found");
      }

      function<int(TreeNode*)> count = [&count](TreeNode* root) {
	if (!root) {
	  return 0;
	}
	return 1+count(root->left)+count(root->right);
      };

      auto lcnt = count(root->left);

      if (k <= lcnt) {
	return kthSmallest(root->left, k);
      } else  {
	k -= lcnt;
	if (k == 1) {
	  return root->val;
	} else {
	  return kthSmallest(root->right, k-1);
	}
      }
    }
};
