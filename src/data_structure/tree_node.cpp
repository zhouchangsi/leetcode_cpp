#include "tree_node.h"
#include "helper.h"

TreeNode::TreeNode(std::string str)
    : TreeNode(leetcode::parse_leetcode_list(str)) {}

TreeNode::TreeNode(std::vector<std::optional<int>> nodes) : TreeNode() {
  if (nodes.size() == 0 || !nodes[0].has_value()) {
    return;
  }
  val = nodes[0].value();
  std::queue<TreeNode*> q;
  q.push(this);
  int i = 1;
  while (!q.empty() && i < nodes.size()) {
    TreeNode* node = q.front();
    q.pop();
    if (nodes[i].has_value()) {
      node->left = new TreeNode(nodes[i].value());
      q.push(node->left);
    }
    i++;
    if (i >= nodes.size()) {
      break;
    }
    if (nodes[i].has_value()) {
      node->right = new TreeNode(nodes[i].value());
      q.push(node->right);
    }
    i++;
  }
}

TreeNode::~TreeNode() {
  delete left, right;
}

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

bool TreeNode::equals(TreeNode* node) {
  std::stack<TreeNode*> a;
  std::stack<TreeNode*> b;
  a.push(this);
  b.push(node);
  while (!a.empty()) {
    TreeNode* this_node = a.top();
    TreeNode* other_node = b.top();
    a.pop();
    b.pop();
    if (this_node->val != other_node->val) {
      return false;
    }
    if (this_node->left != nullptr) {
      a.push(this_node->left);
    }
    if (this_node->right != nullptr) {
      a.push(this_node->right);
    }
    if (other_node->left != nullptr) {
      b.push(other_node->left);
    }
    if (other_node->right != nullptr) {
      b.push(other_node->right);
    }
  }
  return true;
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