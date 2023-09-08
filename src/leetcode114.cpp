/**
 * https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/
 */
#include "common_headers.h"
#include "utils/tree_node.hpp"

using namespace std;

class MyQueue {
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

TEST(leetcode114, case1) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  MyQueue s;
  s.flatten(root);
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->right->val, 2);
  EXPECT_EQ(root->right->right->val, 3);
  EXPECT_EQ(root->right->right->right->val, 4);
  EXPECT_EQ(root->right->right->right->right->val, 5);
  EXPECT_EQ(root->right->right->right->right->right->val, 6);
}