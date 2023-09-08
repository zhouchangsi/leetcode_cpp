#pragma once

#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class TreeTest {
 public:
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

  static TreeNode* from(std::string str) {
    std::vector<std::string> vec;
    std::string tmp;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == ',') {
        vec.push_back(tmp);
        tmp.clear();
      } else {
        tmp += str[i];
      }
    }
    if (!tmp.empty()) {
      vec.push_back(tmp);
    }
    if (vec.empty()) {
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

  static int count_nodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
  }
};

// TEST(tree_node, case1) {
//   TreeNode* root = TreeTest::from("3,9,20,null,null,15,7");
//   EXPECT_EQ(TreeTest::to_string(root), "3,9,20,null,null,15,7");
// }