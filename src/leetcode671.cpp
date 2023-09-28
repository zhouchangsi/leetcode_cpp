#include "common_headers.h"
#include "data_structure/tree_node.hpp"

// class Solution {
//  public:
//   int findSecondMinimumValue(TreeNode* root) {
//     if (root == nullptr) {
//       return -1;
//     }
//     int res = -1;
//     int root_val = root->val;
//     std::queue<TreeNode*> q;
//     for (q.push(root); !q.empty(); q.pop()) {
//       TreeNode* node = q.front();
//       if (node->val != root_val) {
//         res = res == -1 ? node->val : std::min(res, node->val);
//       }
//       if (node->left != nullptr) {
//         q.push(node->left);
//       }
//       if (node->right != nullptr) {
//         q.push(node->right);
//       }
//     }
//     return res;
//   }
// };

class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr) {
      return -1;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return -1;
    }
    int left_val = root->left->val;
    int right_val = root->right->val;
    if (left_val == root->val) {
      left_val = findSecondMinimumValue(root->left);
    }
    if (right_val == root->val) {
      right_val = findSecondMinimumValue(root->right);
    }
    if (left_val != -1 && right_val != -1) {
      return std::min(left_val, right_val);
    }
    if (left_val != -1) {
      return left_val;
    }
    return right_val;
  }
};

TEST(leetcode671, case1) {
  Solution s;
  EXPECT_EQ(s.findSecondMinimumValue(TreeTest::from("2,2,5,null,null,5,7")), 5);
}