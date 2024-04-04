#include "../leetcode/leetcode.h"

class Solution {
  int sum = 0;

 public:
  TreeNode* convertBST(TreeNode* root) {
    if (root == nullptr) return nullptr;
    convertBST(root->right);
    root->val += sum;
    sum = root->val;
    convertBST(root->left);
    return root;
  }
};