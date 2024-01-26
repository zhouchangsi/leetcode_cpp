#pragma once
#include "./common.h"

namespace leetcode {

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
    : val(0)
    , left(nullptr)
    , right(nullptr)
  {
  }
  TreeNode(int x)
    : val(x)
    , left(nullptr)
    , right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x)
    , left(left)
    , right(right)
  {
  }

  ~TreeNode()
  {
    delete left;
    delete right;
  }
};

/**
 * @brief Create a tree object
 *
 * @param str level order traversal string, e.g. "[1,2,3,null,null,4,5]",
 * "1,2,3,null,null,4,5"
 * @return TreeNode*
 */
TreeNode*
create_tree(std::string str)
{
  auto nums = parse_leetcode_list(str);
  TreeNode* root = new TreeNode(nums[0].value());
  std::queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    if (i < nums.size() && nums[i].has_value()) {
      node->left = new TreeNode(nums[i].value());
      q.push(node->left);
    }
    i++;
    if (i < nums.size() && nums[i].has_value()) {
      node->right = new TreeNode(nums[i].value());
      q.push(node->right);
    }
    i++;
  }
  return root;
}

bool
is_same_tree(TreeNode* root1, TreeNode* root2)
{
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }
  if (root1->val != root2->val) {
    return false;
  }
  return is_same_tree(root1->left, root2->left) &&
         is_same_tree(root1->right, root2->right);
}

int
tree_depth(TreeNode* root)
{
  if (root == nullptr) {
    return 0;
  }
  return std::max(tree_depth(root->left), tree_depth(root->right)) + 1;
}

int
tree_size(TreeNode* root)
{
  if (root == nullptr) {
    return 0;
  }
  return tree_size(root->left) + tree_size(root->right) + 1;
}

};