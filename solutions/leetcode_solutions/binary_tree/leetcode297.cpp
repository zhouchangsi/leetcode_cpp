// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/submissions/448037353/
// https://r07na4yqwor.feishu.cn/docx/TqcsdJkpWoGNqcxl6L5c9CeCnRh
#include "../leetcode/env.h"

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "#";
    }
    return to_string(root->val) + ' ' + serialize(root->left) + ' ' +
           serialize(root->right);
  }

  TreeNode* mydeserialize(istringstream& ss) {
    string tmp;
    ss >> tmp;
    if (tmp == "#") {
      return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(tmp));
    node->left = mydeserialize(ss);
    node->right = mydeserialize(ss);
    return node;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    return mydeserialize(ss);
  }
};