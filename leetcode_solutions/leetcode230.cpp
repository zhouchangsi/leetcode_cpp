#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    traverse(root, k);
    return res;
  }

  int res = 0;
  int rank = 0;
  void traverse(TreeNode* root, int k) {
    if (root == nullptr) {
      return;
    }
    traverse(root->left, k);
    rank++;
    if (k == rank) {
      res = root->val;
      return;
    }
    traverse(root->right, k);
  }
};

TEST(leetcode230, solution) {
  TreeNode* root = create_tree("3,1,4,null,2");
  int k = 1;
  int ans = 1;
  EXPECT_EQ(Solution().kthSmallest(root, k), ans);
  delete root;
}