// https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/446139221/
// https://r07na4yqwor.feishu.cn/docx/IdvUdYJvnonbA4x9bSickhVInXf
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};