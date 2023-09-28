#include "common_headers.h"
#include "data_structure/tree_node.hpp"

using namespace std;

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) > 1) {
      return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
  }

  int height(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
  }
};

TEST(leetcode110, case1) {
  Solution solution;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
  EXPECT_TRUE(solution.isBalanced(root));
}