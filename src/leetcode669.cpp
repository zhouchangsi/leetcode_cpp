#include "common_headers.h"
#include "data_structure/tree_node.hpp"

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
  Solution solution;
  TreeNode* root = TreeTest::from("1,0,2");
  TreeNode* expected = TreeTest::from("1,null,2");
  EXPECT_TRUE(TreeTest::is_equals(expected, solution.trimBST(root, 1, 2)));
}