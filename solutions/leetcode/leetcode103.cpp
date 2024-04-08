// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
// https://r07na4yqwor.feishu.cn/docx/VfmcdimMSohCvTxRwRIcavbAnHh
#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.emplace(root);
    bool l2r = true;
    while (!q.empty()) {
      int size = q.size();
      deque<int> row;
      while (size--) {
        auto p = q.front();
        q.pop();
        l2r ? row.emplace_back(p->val) : row.emplace_front(p->val);
        if (p->left) q.emplace(p->left);
        if (p->right) q.emplace(p->right);
      }
      l2r = !l2r;
      res.emplace_back(vector<int>(row.begin(), row.end()));
    }

    return res;
  }
};