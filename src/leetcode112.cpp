#include "common_headers.h"
#include "data_structure/tree_node.hpp"

using namespace std;

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
      return false;
    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};

TEST(leetcode112, case1) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  int targetSum = 22;
  EXPECT_EQ(s.hasPathSum(root, targetSum), true);
}