// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://r07na4yqwor.feishu.cn/docx/GPiMdhZKwoSzwkxIUDOcbfwxnO6
#include "../leetcode.h"

class Solution {
 public:
  // 对于任意一颗树而言，前序遍历的形式总是
  //  [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
  //  即根节点总是前序遍历中的第一个节点。而中序遍历的形式总是
  //  [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;
    const int& root_val = preorder[0];
    TreeNode* root = new TreeNode(root_val);
    const auto& it = find(inorder.begin(), inorder.end(), root_val);

    vector<int> left_inorder(inorder.begin(), it);
    vector<int> right_inorder(it + 1, inorder.end());

    const auto& slice_pos = preorder.begin() + 1 + left_inorder.size();
    vector<int> left_preorder(preorder.begin() + 1, slice_pos);
    vector<int> right_preorder(slice_pos, preorder.end());

    root->left = buildTree(left_preorder, left_inorder);
    root->right = buildTree(right_preorder, right_inorder);
    return root;
  }
};