#include "common_headers.h"
#include "tree_node.h"

using namespace std;

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root == p || root == q) {
      return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
      return root;
    }
    return left != nullptr ? left : right;
  }
};

TEST(leetcode236, solution) {
  {
    TreeNode* root = new TreeNode("6,2,8,0,4,7,9,null,null,3,5");
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* ans = root;
    EXPECT_EQ(Solution().lowestCommonAncestor(root, p, q), ans);
    delete root;
  }
  {
    TreeNode* root = new TreeNode("6,2,8,0,4,7,9,null,null,3,5");
    TreeNode* p = root->left;
    TreeNode* q = root->left->right;
    TreeNode* ans = p;
    EXPECT_EQ(Solution().lowestCommonAncestor(root, p, q), ans);
    delete root;
  }
}
