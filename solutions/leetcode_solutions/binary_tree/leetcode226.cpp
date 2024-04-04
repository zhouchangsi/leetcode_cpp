// https://leetcode.cn/problems/invert-binary-tree/submissions/517738858/
// https://r07na4yqwor.feishu.cn/docx/YnbwdI6WFoGxsUxxJwsccJ2on2d
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* inverted_l = invertTree(root->left);
    TreeNode* inverted_r = invertTree(root->right);
    root->left = inverted_r;
    root->right = inverted_l;
    return root;
  }
};