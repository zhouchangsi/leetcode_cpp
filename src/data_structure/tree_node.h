#pragma once

#include <iostream>
#include <optional>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}

  /**
   * @brief Construct from string, e.g. "[1,2,3,null,null,4,5]"
   */
  TreeNode(std::string str);
  TreeNode(std::vector<std::optional<int>> nodes);
  ~TreeNode();
  int depth();
  int size();
  bool equals(TreeNode* node);
  bool equals(TreeNode& node) {
    TreeNode* _node = &node;
    return equals(_node);
  }
  bool operator==(TreeNode& node) { return equals(node); }
  bool operator!=(TreeNode& node) { return !equals(node); }
};