#include "common_headers.h"
#include "tree_node.h"

using namespace std;

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

TEST(leetcode572, case1) {
  Solution s;
  TreeNode* root = new TreeNode("3,4,5,1,2");
  TreeNode* subRoot = new TreeNode("4,1,2");
  EXPECT_EQ(s.isSubtree(root, subRoot), true);
  delete root, subRoot;
}