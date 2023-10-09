#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  void flatten(TreeNode* root) {
    preorder(root);
    for (int i = 1; i < pre_order_notes.size(); i++) {
      auto p = pre_order_notes[i - 1];
      p->left = nullptr;
      p->right = pre_order_notes[i];
    }
  }

  vector<TreeNode*> pre_order_notes = vector<TreeNode*>();
  vector<TreeNode*> preorder(TreeNode* root) {
    if (root == nullptr) {
      return pre_order_notes;
    }
    pre_order_notes.push_back(root);
    preorder(root->left);
    preorder(root->right);
    return pre_order_notes;
  }
};

TEST(leetcode114, solution) {
  TreeNode* root = create_tree("1,2,5,3,4,null,6");
  Solution s;
  s.flatten(root);
  auto expect = create_tree("1,null,2,null,3,null,4,null,5,null,6");
  EXPECT_TRUE(is_same_tree(root, expect));
  delete root, expect;
}