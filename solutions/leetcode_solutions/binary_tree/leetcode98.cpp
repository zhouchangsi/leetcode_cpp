// https://leetcode.cn/problems/validate-binary-search-tree/
// https://r07na4yqwor.feishu.cn/docx/XfdkdzWcUoTCOyxe7mqcitT1nBh
#include "../leetcode/env.h"

class Solution {
 public:
  bool helper(TreeNode* root, long long lower, long long upper) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= lower || root->val >= upper) {
      return false;
    }
    return helper(root->left, lower, root->val) &&
           helper(root->right, root->val, upper);
  }
  bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
};