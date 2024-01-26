#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left != nullptr && root->left->left == nullptr &&
        root->left->right == nullptr) {
      return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};

TEST(leetcode404, solution) {
  Solution s;
  TreeNode* root = create_tree("3,9,20,null,null,15,7");
  EXPECT_EQ(s.sumOfLeftLeaves(root), 24);
  delete root;
}