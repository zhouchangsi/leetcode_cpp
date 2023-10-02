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

  int depth();

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

  bool operator==(TreeNode* node) { return equals(node); }
  int size();
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

  /**
   * @brief
   * TreeTest::from("5,4,5,1,1,5");
   * @param str
   * @return TreeNode*
   */
  static TreeNode* from(std::string str) {
    std::vector<std::string> vec;
    std::stringstream ss(str);
    std::string item;
    while (getline(ss, item, ',')) {
      vec.push_back(item);
    }
    if (vec.size() == 0) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(std::stoi(vec[0]));
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (i < vec.size() && vec[i] != "null") {
        node->left = new TreeNode(std::stoi(vec[i]));
        q.push(node->left);
      }
      i++;
      if (i < vec.size() && vec[i] != "null") {
        node->right = new TreeNode(std::stoi(vec[i]));
        q.push(node->right);
      }
      i++;
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