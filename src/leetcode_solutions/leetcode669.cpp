#include "common_headers.h"
#include "tree_node.h"

using namespace std;

class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val < low) {
      return trimBST(root->right, low, high);
    }
    if (root->val > high) {
      return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};

TEST(leetcode669, sampleInputByProblem1) {
  Solution s;
  TreeNode* root = new TreeNode("1,0,2");
  TreeNode* expect = new TreeNode("1,null,2");
  TreeNode* result = s.trimBST(root, 1, 2);
  EXPECT_TRUE(result->equals(expect));
  delete root, expect, result;
}