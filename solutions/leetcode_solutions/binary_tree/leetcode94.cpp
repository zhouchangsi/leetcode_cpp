// https://leetcode.cn/problems/binary-tree-inorder-traversal
#include "../leetcode/env.h"

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node == nullptr) return;
      dfs(node->left);
      res.push_back(node->val);
      dfs(node->right);
    };
    dfs(root);
    return res;
  }
};