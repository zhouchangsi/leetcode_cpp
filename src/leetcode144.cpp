#include "common_headers.h"
#include "data_structure/tree_node.hpp"

using namespace std;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }

    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      stack.pop();
      if (node == nullptr) {
        continue;
      }
      result.push_back(node->val);
      stack.push(node->right);
      stack.push(node->left);
    }
    return result;
  }
};

TEST(leetcode144, solution) {
  Solution solution;
  {
    TreeNode* root = TreeTest::from("1,null,2,3");
    vector<int> result = solution.preorderTraversal(root);
    vector<int> expected = {1, 2, 3};
    EXPECT_EQ(result, expected);
  }
}