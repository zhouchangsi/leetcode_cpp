#include "leetcode.h"

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> res;
    if (root) q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (i == 0) res.push_back(node->val);
        if (node->right) q.push(node->right);
        if (node->left) q.push(node->left);
      }
    }
    return res;
  }
};