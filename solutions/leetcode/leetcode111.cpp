// https://leetcode.cn/problems/minimum-depth-of-binary-tree/
// https://r07na4yqwor.feishu.cn/docx/DFVDdeDKloiQMMxxvqWceZVmnmb
#include "../leetcode.h"

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    const int left = minDepth(root->left);
    const int right = minDepth(root->right);
    if (root->left == nullptr) return right + 1;
    if (root->right == nullptr) return left + 1;
    return min(left, right) + 1;
  }
};