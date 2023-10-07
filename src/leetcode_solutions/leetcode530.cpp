#include "common_headers.h"
#include "tree_node.h"

using namespace std;

class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    int ans = INT_MAX;
    int pre = -1;
    traverse(root, pre, ans);
    return ans;
  }
  void traverse(TreeNode* root, int& pre, int& ans) {
    if (root == nullptr) {
      return;
    }
    traverse(root->left, pre, ans);
    if (pre != -1) {
      ans = min(ans, root->val - pre);
    }
    pre = root->val;
    traverse(root->right, pre, ans);
  }
};

TEST(leetcode530, solution) {
  TreeNode* root = new TreeNode("1,null,3,2");
  int ans = 1;
  EXPECT_EQ(Solution().getMinimumDifference(root), ans);
  delete root;
}