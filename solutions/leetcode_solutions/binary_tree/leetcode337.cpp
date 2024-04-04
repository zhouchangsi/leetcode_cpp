// https://leetcode.cn/problems/house-robber-iii/
// https://r07na4yqwor.feishu.cn/docx/IiindP5Aho8d4wxAerPc3h5Knvf
#include "../leetcode/env.h"

struct SubtreeStatus {
  int selected;
  int not_selected;
};

class Solution {
 public:
  SubtreeStatus dfs(TreeNode* node) {
    if (!node) {
      return {0, 0};
    }
    auto l = dfs(node->left);
    auto r = dfs(node->right);
    int selected = node->val + l.not_selected + r.not_selected;
    int not_selected =
        max(l.selected, l.not_selected) + max(r.selected, r.not_selected);
    return {selected, not_selected};
  }

  int rob(TreeNode* root) {
    auto root_status = dfs(root);
    return max(root_status.selected, root_status.not_selected);
  }
};