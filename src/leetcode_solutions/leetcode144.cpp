#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

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
    TreeNode* root = create_tree("1,null,2,3");
    vector<int> result = solution.preorderTraversal(root);
    vector<int> expected = {1, 2, 3};
    EXPECT_EQ(result, expected);
    delete root;
  }
}