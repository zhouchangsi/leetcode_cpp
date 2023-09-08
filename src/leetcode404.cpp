#include "common_headers.h"
#include "utils/tree_node.hpp"

using namespace std;

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

TEST(leetcode404, case1) {
  Solution s;
  TreeNode* root = TreeTest::from("3,9,20,null,null,15,7");
  EXPECT_EQ(s.sumOfLeftLeaves(root), 24);
}