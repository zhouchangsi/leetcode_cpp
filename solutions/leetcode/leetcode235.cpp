// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// https://r07na4yqwor.feishu.cn/docx/PFfydt6dlo1S9LxacZ9cb9rAnTd
#include "../leetcode.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((long long)(root->val - p->val) * ( root->val - q->val) <= 0) return root;
        return lowestCommonAncestor(p->val < root->val ? root->left: root->right, p, q);
    }
};