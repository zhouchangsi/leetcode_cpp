#pragma once

#include <iostream>
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

  int depth() {
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

  bool equals(TreeNode* node) {
    std::stack<TreeNode*> nodes;
    std::stack<TreeNode*> nodes2;
    nodes.push(this);
    nodes2.push(node);
    while (!nodes.empty()) {
      TreeNode* node = nodes.top();
      TreeNode* node2 = nodes2.top();
      nodes.pop();
      nodes2.pop();
      if (node->val != node2->val) {
        return false;
      }
      if (node->left != nullptr) {
        nodes.push(node->left);
      }
      if (node->right != nullptr) {
        nodes.push(node->right);
      }
      if (node2->left != nullptr) {
        nodes2.push(node2->left);
      }
      if (node2->right != nullptr) {
        nodes2.push(node2->right);
      }
    }
    return true;
  }

  int size() {
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
};

class TreeTest {
 public:
  static int count_nodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
  }

  static int depth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + std::max(depth(root->left), depth(root->right));
  }

  static TreeNode* from(std::string str) {
    auto split = [](const std::string& s, char delim) {
      std::vector<std::string> items;
      std::stringstream string_stream(s);
      std::string item;
      while (std::getline(string_stream, item, delim)) {
        items.push_back(item);
      }
      return items;
    };
    std::vector<std::string> nodes = split(str, ',');
    if (nodes.empty()) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(std::stoi(nodes[0]));
    std::queue<TreeNode*> queue;
    queue.push(root);
    for (int i = 1; i < nodes.size(); i += 2) {
      TreeNode* node = queue.front();
      queue.pop();
      if (nodes[i] != "null") {
        node->left = new TreeNode(std::stoi(nodes[i]));
        queue.push(node->left);
      }
      if (i + 1 < nodes.size() && nodes[i + 1] != "null") {
        node->right = new TreeNode(std::stoi(nodes[i + 1]));
        queue.push(node->right);
      }
    }
    return root;
  }

  static bool is_equals(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) {
      return true;
    }
    if (t1 == nullptr || t2 == nullptr) {
      return false;
    }
    if (t1->val != t2->val) {
      return false;
    }
    return is_equals(t1->left, t2->left) && is_equals(t1->right, t2->right);
  }

  /**
   * print tree and using "_" to connect the node
   *    ____6____
   *  __2__   __8__
   * _0_ _4_ _7_ _9_
   * # # 3 5 # # # #
   *
   */
  static void print(TreeNode* root, unsigned int tab_size = 2) {
    if (root == nullptr) {
      return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      int n = q.size();
      std::string tab(tab_size * (1 << depth) - 1, ' ');
      for (int i = 0; i < n; ++i) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << tab << node->val;
        if (i < n - 1) {
          std::cout << tab;
        }
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
      std::cout << std::endl;
      depth++;
    }
  }

  static std::string to_string(TreeNode* root) {
    int n = count_nodes(root);
    std::string str;
    std::queue<TreeNode*> q;
    q.push(root);
    for (int cnt = 0; !q.empty(); q.pop()) {
      TreeNode* node = q.front();
      if (node == nullptr) {
        str += "null,";
      } else {
        bool is_last = ++cnt == n;
        str += std::to_string(node->val) + (is_last ? "" : ",");
        if (is_last) {
          break;
        }
        q.push(node->left);
        q.push(node->right);
      }
    }
    return str;
  }
};