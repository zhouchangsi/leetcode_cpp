#include "tree_node.hpp"

int TreeNode::depth() {
  std::stack<TreeNode*> nodes;
  std::stack<int> depths;
  nodes.push(this);
  depths.push(1);
  int max_depth = 0;
  while (!nodes.empty()) {
    TreeNode* node = nodes.top();
    nodes.pop();
    int _depth = depths.top();
    depths.pop();
    max_depth = std::max(max_depth, _depth);
    if (node->left != nullptr) {
      nodes.push(node->left);
      depths.push(_depth + 1);
    }
    if (node->right != nullptr) {
      nodes.push(node->right);
      depths.push(_depth + 1);
    }
  }
  return max_depth;
}

int TreeNode::size() {
  std::stack<TreeNode*> nodes;
  nodes.push(this);
  int _size = 0;
  while (!nodes.empty()) {
    TreeNode* node = nodes.top();
    nodes.pop();
    _size++;
    if (node->left != nullptr) {
      nodes.push(node->left);
    }
    if (node->right != nullptr) {
      nodes.push(node->right);
    }
  }
  return _size;
}