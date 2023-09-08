#include "common_headers.h"
#include "utils/tree_node.hpp"

using namespace std;

class Solution {
 public:
  int longestUnivaluePath(TreeNode* root) {
    dfs(root);
    return res;
  }

 private:
  int res = 0;
  int dfs(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int left = dfs(root->left);
    int right = dfs(root->right);
    int left_path = 0;
    int right_path = 0;
    if (root->left != nullptr && root->left->val == root->val) {
      left_path = left + 1;
    }
    if (root->right != nullptr && root->right->val == root->val) {
      right_path = right + 1;
    }
    res = max(res, left_path + right_path);
    return max(left_path, right_path);
  }
};

TEST(leetcode678, case1) {
  Solution s;
  EXPECT_EQ(s.longestUnivaluePath(TreeTest::from("5,4,5,1,1,5")), 2);
}