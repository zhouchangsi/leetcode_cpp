#include "./leetcode/env.h"

class Solution
{
public:
  int max_diameter = 0;
  int depth(TreeNode* root)
  {
    if (root == nullptr) {
      return 0;
    }
    return max(depth(root->left), depth(root->right)) + 1;
  }
  int sum_of_depth(TreeNode* root)
  {
    if (root == nullptr) {
      return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    max_diameter = max(max_diameter, left + right);
    return max(left, right) + 1;
  }

  int diameterOfBinaryTree(TreeNode* root)
  {
    sum_of_depth(root);
    if (root->left)
      sum_of_depth(root->left);
    return max_diameter;
  }
};