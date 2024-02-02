#include "./leetcode/env.h"

// leeetcode 145. 二叉树的后序遍历
class Solution
{
public:
  vector<int> res;
  vector<int> postorderTraversal(TreeNode* root)
  {
    if (!root) return res;
    if (root->left) postorderTraversal(root->left);
    if (root->right) postorderTraversal(root->right);
    res.emplace_back(root->val);
    return res;
  }
};