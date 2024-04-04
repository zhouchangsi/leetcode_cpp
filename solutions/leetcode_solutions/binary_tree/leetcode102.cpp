// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// https://r07na4yqwor.feishu.cn/docx/FqDrdVQnloX1PsxA4YmcOL59ncb
#include "../leetcode/env.h"

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> row;
      while (size--) {
        TreeNode* node = q.front();
        q.pop();
        row.emplace_back(node->val);
        if (node->left) q.emplace(node->left);
        if (node->right) q.emplace(node->right);
      }
      res.emplace_back(row);
    }

    return res;
  }
};