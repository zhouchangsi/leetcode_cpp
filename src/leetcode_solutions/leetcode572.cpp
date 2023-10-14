#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr)
      return false;
    if (is_same_tree(root, subRoot))
      return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool is_same_tree(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr)
      return true;
    if (a == nullptr || b == nullptr)
      return false;
    if (a->val != b->val)
      return false;
    return is_same_tree(a->left, b->left) && is_same_tree(a->right, b->right);
  }
};

TEST(leetcode572, solution) {
  Solution s;
  TreeNode* root = create_tree("3,4,5,1,2");
  TreeNode* subRoot = create_tree("4,1,2");
  EXPECT_EQ(s.isSubtree(root, subRoot), true);
}