#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

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

TEST(leetcode110, solution) {
  Solution solution;
  auto root = create_tree("3,9,20,null,null,15,7");
  EXPECT_TRUE(solution.isBalanced(root));
  delete root;
}