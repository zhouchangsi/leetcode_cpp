/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
    int maxSum = INT32_MIN;
    int maxGain(TreeNode* root){
        if(root == nullptr) return 0;
        int left_gain = max(maxGain(root->left), 0);
        int right_gain = max(maxGain(root->right), 0);
        int lmr = root->val + left_gain + right_gain;
        maxSum = max(maxSum, lmr);
        return root->val + max(left_gain, right_gain);
    }
};