// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> result;
      if (!root) {
        return result;
      }

      vector<TreeNode*> next{root};
      while (!next.empty()) {
        vector<TreeNode*> curr;
        curr.swap(next);

        vector<int> level;
        level.reserve(curr.size());
        for (auto& node : curr) {
          level.push_back(node->val);
          if (node->left) {
            next.push_back(node->left);
          }
          if (node->right) {
            next.push_back(node->right);
          }
        }
        result.emplace_back(move(level));
      }
      return result;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> result;
      if (!root) {
        return result;
      }

      vector<TreeNode*> curr{root};

      bool zig = true;
      vector<TreeNode*> next;
      while (!curr.empty()) {
        vector<int> level;
        level.reserve(curr.size());
        for (auto n : curr) {
          level.push_back(n->val);
          if (n->left) { next.push_back(n->left); }
          if (n->right) { next.push_back(n->right); }
        }

        if (!zig) {
          reverse(level.begin(), level.end());
        }
        result.push_back(move(level));

        curr.swap(next);
        next.clear();
        zig = !zig;
      }
      return result;
    }
};
