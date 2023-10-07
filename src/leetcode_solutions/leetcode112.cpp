#include "common_headers.h"
#include "tree_node.h"

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
  TreeNode* root = new TreeNode("5,4,8,11,null,13,4,7,2,null,null,null,1");
  int targetSum = 22;
  EXPECT_EQ(s.hasPathSum(root, targetSum), true);
  delete root;
}