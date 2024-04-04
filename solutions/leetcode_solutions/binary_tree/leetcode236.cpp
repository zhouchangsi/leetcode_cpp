// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
// https://r07na4yqwor.feishu.cn/docx/JOUOdPjNaoJnLPx99chcsksUntd
#include "../leetcode/env.h"

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root == p || root == q) {
      return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
      return root;
    }
    return left != nullptr ? left : right;
  }
};
