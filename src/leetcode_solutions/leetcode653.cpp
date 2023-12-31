#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  unordered_set<int> set;

  bool findTarget(TreeNode* root, int k) {
    if (root == nullptr) {
      return false;
    }
    if (set.count(k - root->val)) {
      return true;
    }
    set.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};

TEST(leetcode653, solution) {
  TreeNode* root = create_tree("5,3,6,2,4,null,7");
  int k = 9;
  bool ans = true;
  Solution s;
  EXPECT_EQ(s.findTarget(root, k), ans);
}